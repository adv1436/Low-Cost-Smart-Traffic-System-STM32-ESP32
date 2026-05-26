// ======================================================
// TRAFFIC LED PINS
// ======================================================

// Junction 1
#define J1_RED     PB0
#define J1_YELLOW  PB1
#define J1_GREEN   PB12

// Junction 2
#define J2_RED     PB13
#define J2_YELLOW  PB14
#define J2_GREEN   PB15

// Junction 3
#define J3_RED     PA0
#define J3_YELLOW  PA1
#define J3_GREEN   PA4

// Junction 4
#define J4_RED     PA5
#define J4_YELLOW  PA6
#define J4_GREEN   PA7

// ======================================================
// BUZZERS
// ======================================================

#define BUZZER1 PB7
#define BUZZER2 PC13

// ======================================================
// IR SENSORS
// ======================================================

#define IR1 PA11
#define IR2 PA12

// ======================================================
// VARIABLES
// ======================================================

unsigned long ir2Time = 0;
unsigned long ir1Time = 0;

bool ir2Detected = false;

// ======================================================
// FUNCTION DECLARATIONS
// ======================================================

void allRed();
void checkWrongSide();
void runJunction(int redPin, int yellowPin, int greenPin);

// ======================================================
// SETUP
// ======================================================

void setup()
{
    // =========================
    // LED OUTPUTS
    // =========================

    pinMode(J1_RED, OUTPUT);
    pinMode(J1_YELLOW, OUTPUT);
    pinMode(J1_GREEN, OUTPUT);

    pinMode(J2_RED, OUTPUT);
    pinMode(J2_YELLOW, OUTPUT);
    pinMode(J2_GREEN, OUTPUT);

    pinMode(J3_RED, OUTPUT);
    pinMode(J3_YELLOW, OUTPUT);
    pinMode(J3_GREEN, OUTPUT);

    pinMode(J4_RED, OUTPUT);
    pinMode(J4_YELLOW, OUTPUT);
    pinMode(J4_GREEN, OUTPUT);

    // =========================
    // BUZZERS
    // =========================

    pinMode(BUZZER1, OUTPUT);
    pinMode(BUZZER2, OUTPUT);

    digitalWrite(BUZZER1, LOW);
    digitalWrite(BUZZER2, LOW);

    // =========================
    // IR SENSORS
    // =========================

    pinMode(IR1, INPUT);
    pinMode(IR2, INPUT);

    // =========================
    // UART
    // =========================

    Serial1.begin(9600);

    allRed();

    Serial1.println("SMART TRAFFIC SYSTEM READY");
}

// ======================================================
// MAIN LOOP
// ======================================================

void loop()
{
    runJunction(J1_RED, J1_YELLOW, J1_GREEN);
    runJunction(J2_RED, J2_YELLOW, J2_GREEN);
    runJunction(J3_RED, J3_YELLOW, J3_GREEN);
    runJunction(J4_RED, J4_YELLOW, J4_GREEN);
}

// ======================================================
// ALL RED FUNCTION
// ======================================================

void allRed()
{
    digitalWrite(J1_RED, HIGH);
    digitalWrite(J2_RED, HIGH);
    digitalWrite(J3_RED, HIGH);
    digitalWrite(J4_RED, HIGH);

    digitalWrite(J1_YELLOW, LOW);
    digitalWrite(J2_YELLOW, LOW);
    digitalWrite(J3_YELLOW, LOW);
    digitalWrite(J4_YELLOW, LOW);

    digitalWrite(J1_GREEN, LOW);
    digitalWrite(J2_GREEN, LOW);
    digitalWrite(J3_GREEN, LOW);
    digitalWrite(J4_GREEN, LOW);
}

// ======================================================
// RUN SINGLE JUNCTION
// ======================================================

void runJunction(int redPin, int yellowPin, int greenPin)
{
    // RED OFF
    digitalWrite(redPin, LOW);

    // GREEN ON
    digitalWrite(greenPin, HIGH);

    // 5 SECOND GREEN
    unsigned long startTime = millis();

    while (millis() - startTime < 5000)
    {
        checkWrongSide();
    }

    // GREEN OFF
    digitalWrite(greenPin, LOW);

    // YELLOW ON
    digitalWrite(yellowPin, HIGH);

    // 2 SECOND YELLOW
    startTime = millis();

    while (millis() - startTime < 2000)
    {
        checkWrongSide();
    }

    // YELLOW OFF
    digitalWrite(yellowPin, LOW);

    // RED ON
    digitalWrite(redPin, HIGH);
}

// ======================================================
// WRONG SIDE + COLLISION CHECK
// ======================================================

void checkWrongSide()
{
    // =====================================
    // IR2 FIRST
    // =====================================

    if (digitalRead(IR2) == LOW && !ir2Detected)
    {
        ir2Detected = true;

        ir2Time = millis();

        Serial1.println("IR2 Triggered");

        delay(200);
    }

    // =====================================
    // IR1 AFTER IR2
    // =====================================

    if (ir2Detected && digitalRead(IR1) == LOW)
    {
        ir1Time = millis();

        unsigned long timeDifference = ir1Time - ir2Time;

        Serial1.print("Time Difference: ");
        Serial1.println(timeDifference);

        // =====================================
        // LOW RISK
        // =====================================

        if (timeDifference > 1500)
        {
            Serial1.println("LOW RISK WRONG SIDE");

            digitalWrite(BUZZER1, HIGH);
            delay(500);
            digitalWrite(BUZZER1, LOW);
        }

        // =====================================
        // MEDIUM RISK
        // =====================================

        else if (timeDifference > 700)
        {
            Serial1.println("MEDIUM COLLISION RISK");

            for (int i = 0; i < 3; i++)
            {
                digitalWrite(BUZZER1, HIGH);
                delay(200);

                digitalWrite(BUZZER1, LOW);
                delay(200);
            }
        }

        // =====================================
        // HIGH RISK
        // =====================================

        else
        {
            Serial1.println("HIGH COLLISION RISK");

            digitalWrite(BUZZER1, HIGH);
            digitalWrite(BUZZER2, HIGH);

            delay(3000);

            digitalWrite(BUZZER1, LOW);
            digitalWrite(BUZZER2, LOW);
        }

        ir2Detected = false;

        delay(500);
    }
}
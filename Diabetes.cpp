#include <bits/stdc++.h>
using namespace std;

class Diabetes {
private:
    char name[40];
    float age;
    int wt;
    float ht;
    char sex;
    char s[10]; // Changed from pointer to array for proper indexing

public:
    void welcome_screen(void);
    void getvalue(void);
    void getlevel1_symptoms(void);
    void getlevel2_symptoms(void);
    void getlevel3_symptoms(void);
    int analyse_symptoms(int);
    char display_message(int, int);
};

void diagnosis(void); // Moved outside of main to avoid function nesting

int main() {
    char choice, cho;
    float m;
    int n = 1;

    Diabetes dts;
    dts.welcome_screen();
    dts.getvalue();
    diagnosis();
    dts.getlevel1_symptoms();
    m = dts.analyse_symptoms(n);
    choice = dts.display_message(n, m);
    choice = toupper(choice);

    if (choice == 'Y') {
        ++n;
        dts.getlevel2_symptoms();
        m = dts.analyse_symptoms(n);
        choice = dts.display_message(n, m);
        choice = toupper(choice);

        if (choice == 'Y') {
            ++n;
            dts.getlevel3_symptoms();
            m = dts.analyse_symptoms(n);
            cho = dts.display_message(n, m);
            cho = toupper(cho);

            if (cho == 'Y') {
                ++n;
                dts.getlevel3_symptoms();
                m = dts.analyse_symptoms(n);
                choice = dts.display_message(n, m);
            }
        }
    }

    return 0;
}

void Diabetes::welcome_screen() {
    system("cls"); // we can Replaced clrscr() with system("cls") for cross-platform compatibility
    cout << "********* W E L C O M E *********\n";
    cout << "M E D I C A L   D I A G N O S I S   S O F T W A R E\n";
    cout << "******** PRESS ANY KEY TO CONTINUE *********\n";
    cin.get();
}

void Diabetes::getvalue() {
    system("cls");
    cout << "P E R S O N A L   I N F O R M A T I O N\n";
    cout << "N A M E        : ";
    cin.getline(name, 40);
    cout << "A G E          : ";
    cin >> age;
    cout << "W E I G H T    : ";
    cin >> wt;
    cout << "H E I G H T    : ";
    cin >> ht;
    cout << "S E X (M/F)    : ";
    cin >> sex;
    cin.ignore(); // To ignore the newline character left in the buffer
}

void diagnosis() {
    system("cls");
    cout << " **  D I A G N O S I S   W I N D O W **\n";
    cout << "Let’s have a look at symptoms...\n";
    cout << "Please enter the form on the next page.\n";
    cout << "***** PRESS ANY KEY *****\n";
    cin.get();
}

void Diabetes::getlevel1_symptoms() {
    system("cls");
    int i = 0;
    cout << " *** MEDICAL DIAGNOSIS FORM ***\n";
    cout << "APPETITE (H(HIGH),/L(LOW),/N(NORMAL)): ";
    cin >> s[i];
    s[i] = toupper(s[i]);
    ++i;

    cout << "FREQUENCY OF THIRST(H(HIGH),/L(LOW)/N(NORMAL)): ";
    cin >> s[i];
    s[i] = toupper(s[i]);
    ++i;

    cout << "FREQUENCY OF URINATION(H(HIGH),/L(LOW),/N(NORMAL)): ";
    cin >> s[i];
    s[i] = toupper(s[i]);
    ++i;

    cout << "VISION (I(IMPAIRMENT),/N(NORMAL)): ";
    cin >> s[i];
    s[i] = toupper(s[i]);
    ++i;

    cout << "URINE SUGAR(P(PASSIVE)/A(ACTIVE)): ";
    cin >> s[i];
    s[i] = toupper(s[i]);
    ++i;

    cout << "KETONUREA(P(PASSIVE)/A(ACTIVE)): ";
    cin >> s[i];
    s[i] = toupper(s[i]);
    ++i;

    cout << "FASTING BLOOD SUGAR(H(HIGH)/L(LOW)/N(NORMAL)): ";
    cin >> s[i];
    s[i] = toupper(s[i]);
    ++i;

    cout << "R B S (H(HIGH)/L(LOW)/N(NORMAL)): ";
    cin >> s[i];
    s[i] = toupper(s[i]);
    ++i;

    cout << "FAMILY HISTORY OF DIABETES(P(PASSIVE)/A(ACTIVE)): ";
    cin >> s[i];
    s[i] = toupper(s[i]);
    ++i;

    cout << "OGTT(D/N): ";
    cin >> s[i];
    s[i] = toupper(s[i]);
    ++i;
}

int Diabetes::analyse_symptoms(int n) {
    int count = 0;
    int result = 0;

    switch (n) {
    case 1:
        if (s[9] == 'D') {
            result = -1;
        } else if (s[5] == 'P' && s[6] == 'P' && s[7] == 'H') {
            result = -1;
        } else {
            for (int i = 0; i < 10; i++) {
                if (s[i] == 'H' || s[i] == 'P' || s[i] == 'D' || s[i] == 'I')
                    count++;
            }
            if (count > 5)
                result = -1;
        }
        break;

    case 2:
        if (s[0] == 'P' || s[1] == 'P' || s[2] == 'P' || s[3] == 'H' || s[4] == 'P' || s[5] == 'P' || s[6] == 'P')
            result = -1;
        else
            result = 0;
        break;

    case 3:
        if ((s[0] == 'Y' && s[1] == 'N' && s[2] == 'W' && s[3] == 'P' && s[4] == 'P') ||
            (s[0] == 'Y' && s[1] == 'B' && s[2] == 'W' && s[3] == 'P' && s[4] == 'P') ||
            (s[0] == 'Y' && s[1] == 'N' && s[2] == 'M' && s[3] == 'P' && s[4] == 'P') ||
            (s[0] == 'Y' && s[1] == 'N' && s[2] == 'Y' && s[3] == 'P' && s[4] == 'P'))
            result = 0;
        else
            result = -1;
        break;

    default:
        break;
    }

    return result;
}

char Diabetes::display_message(int n, int m) {
    char ch = 'N'; // Initialize ch
    system("cls");

    switch (n) {
    case 1:
        if (m == 0) {
            cout << "THE PERSON IS NOT DIABETIC\n";
            cout << "PRESS ANY KEY TO QUIT.\n";
            exit(0);
        } else if (m == -1) {
            cout << "THE PERSON IS DIABETIC\n";
            cout << "PROCEED (Y/N)? ";
            cin >> ch;
        }
        break;

    case 2:
        if (m == 0) {
            cout << "IT IS PRIMARY DIABETES.\n";
            cout << "Proceed (Y/N)? ";
            cin >> ch;
        } else if (m == -1) {
            cout << "IT IS SECONDARY DIABETES.\n";
            cout << "PRESS ANY KEY TO QUIT.\n";
            cin.get();
        }
        break;

    case 3:
        if (m == 0) {
            cout << "IT IS INSULIN DEPENDENT DIABETES.\n";
            cout << "Press any key to quit.\n";
            cin.get();
        } else if (m == -1) {
            cout << "IT IS NON INSULIN DEPENDENT DIABETES.\n";
            cout << "PRESS ANY KEY TO QUIT.\n";
            cin.get();
        }
        break;

    default:
        break;
    }

    return ch;
}

void Diabetes::getlevel2_symptoms() {
    system("cls");
    int j = 0;

    cout << "PANCREATITIS (P/A): ";
    cin >> s[j];
    s[j] = toupper(s[j]);
    j++;

    cout << "CARCINOMA (P/A): ";
    cin >> s[j];
    s[j] = toupper(s[j]);
    j++;

    cout << "CIRRHOSIS (P/A): ";
    cin >> s[j];
    s[j] = toupper(s[j]);
    j++;

    cout << "HCTS (H/L/N): ";
    cin >> s[j];
    s[j] = toupper(s[j]);
    j++;

    cout << "HEPATITIS (P/A): ";
    cin >> s[j];
    s[j] = toupper(s[j]);
    j++;

    cout << "HORMONAL DISORDER (P/A): ";
    cin >> s[j];
    s[j] = toupper(s[j]);
    j++;

    cout << "PANCREATECTOMY (P/A): ";
    cin >> s[j];
    s[j] = toupper(s[j]);
    j++;
}

void Diabetes::getlevel3_symptoms() {
    system("cls");
    int k = 0;

    cout << "AGE (Young(Y)/Middle aged(M)/Elderly(E)): ";
    cin >> s[k];
    s[k] = toupper(s[k]);
    k++;

    cout << "BODY WEIGHT (Normal(N)/Above normal(A)/Below normal(B)/Obese(O)): ";
    cin >> s[k];
    s[k] = toupper(s[k]);
    k++;

    cout << "DURATION (Weeks(W)/Months(M)/Years(Y)): ";
    cin >> s[k];
    s[k] = toupper(s[k]);
    k++;

    cout << "KETONUREA (P/A): ";
    cin >> s[k];
    s[k] = toupper(s[k]);
    k++;

    cout << "AUTO ANTIBODIES (P/A): ";
    cin >> s[k];
    s[k] = toupper(s[k]);
    k++;
}

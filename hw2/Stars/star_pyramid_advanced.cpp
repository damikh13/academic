#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    unsigned short number_of_rows, type;
    cout << "number of rows: "; cin >> number_of_rows;
    cout << "which type: "; cin >> type;
    // cin >> number_of_rows >> type;
    switch (type) {
        case 1:
            for (int i = 1; i <= number_of_rows; ++i) {
                for (int j = 1; j <= i; ++j) {
                    cout << '*';
                }
                cout << endl;
            }
            break;
        case 2:
            for (int i = number_of_rows; i > 0; --i) {
                for (int j = 1; j <= i; ++j) {
                    cout << '*';
                }
                cout << endl;
            }
            break;
        case 3:
            for (int i = 1; i <= number_of_rows; ++i) {
                for (int j = 0; j < (number_of_rows - i); ++j) {
                    cout << ' ';
                }
                for (int j = 0; j < i; ++j) {
                    cout << '*';
                }
                cout << endl;
            }
            break;
        case 4:
            for (int i = number_of_rows; i > 0; --i) {
                // (number_of_rows - 10) пробелов и (number_of_rows - 0) звёздочек
                // (number_of_rows - 9) пробелов и (number_of_rows - 1) звёздочек
                // (number_of_rows - 8) пробелов и (number_of_rows - 2) звёздочек
                // (number_of_rows - 7) пробелов и (number_of_rows - 3) звёздочек
                for (int j = 0; j < (number_of_rows - i); ++j) {
                    cout << ' ';
                }
                for (int j = 0; j < number_of_rows - (number_of_rows - i); ++j) {
                    cout << '*';
                }
                cout << endl;
            }
            break;
        case 5:
            // upper side of the figure
            for (int i = 1; i <= number_of_rows; ++i) {
                // 1st group of spaces
                for (int j = 0; j < (number_of_rows - i); ++j) {
                    cout << ' ';
                }

                // stars
                for (int j = 0; j < 1 + 2 * (i - 1); ++j) {
                    cout << '*';
                }

                // 2nd group of spaces
                for (int j = 0; j < (number_of_rows - i); ++j) {
                    cout << ' ';
                }
                
                // go to the next row
                cout << endl;
            }

            // bottom side of the figure
            for (int i = (number_of_rows - 1); i > 0; --i) {
                // 1st group of spaces
                for (int j = 0; j < (number_of_rows - i); ++j) {
                    cout << ' ';
                }

                // stars
                for (int j = 0; j < 1 + 2 * (i - 1); ++j) {
                    cout << '*';
                }

                // 2nd group of spaces
                for (int j = 0; j < (number_of_rows - i); ++j) {
                    cout << ' ';
                }
                
                // go to the next row
                cout << endl;
            }
            /*
            _____*_____  1 -- (number_of_rows - 1) пробел и (1 + 2 * 0) звёздочек и (number_of_rows - 1) пробел
            ____***____ 2 -- (number_of_rows - 2) пробела и (1 + 2 * 1) звёздочек и (number_of_rows - 2) пробела
            ___*****___ 3 -- (number_of_rows - 3) пробела и (1 + 2 * 2) звёздочек и (number_of_rows - 3) пробела
            __*******__ 4 -- (number_of_rows - 4) пробела и (1 + 2 * 3) звёздочек и (number_of_rows - 4) пробела
            _*********_ 5 -- (number_of_rows - 5) пробелов и (1 + 2 * 4) звёздочек и (number_of_rows - 5) пробелов
            *********** 6 -- (number_of_rows - 6) пробелов и (1 + 2 * 5) звёздочек и (number_of_rows - 6) пробелов
            _*********_ 7 -- (number_of_rows - 5) пробелов и (1 + 2 * 4) звёздочек и (number_of_rows - 5) пробелов
            __*******__ 8 -- (number_of_rows - 4) пробелов и (1 + 2 * 3) звёздочек и (number_of_rows - 4) пробела
            ___*****___ 9 -- (number_of_rows - 3) пробелов и (1 + 2 * 2) звёздочек и (number_of_rows - 3) пробела
            ____***____ 10 -- (number_of_rows - 2) пробела и (1 + 1 * 1) звёздочек и (number_of_rows - 2) пробела
            _____*_____ 11 -- (number_of_rows - 1) пробел и (1 + 2 * 0) звёздочек и (number_of_rows - 1) пробел
            */
            break;
        case 6:
            cout << "cnt_of_figures: ";
            unsigned short int cnt_of_figures; cin >> cnt_of_figures;            // upper side of the figure
            // upper side of the figure K times:
            for (int i = 1; i <= number_of_rows; ++i) {
                for (int k = 0; k < cnt_of_figures; ++k) {
                    // 1st group of spaces
                    for (int j = 0; j < (number_of_rows - i); ++j) {
                        cout << ' ';
                    }

                    // stars
                    for (int j = 0; j < 1 + 2 * (i - 1); ++j) {
                        cout << '*';
                    }

                    // 2nd group of spaces
                    for (int j = 0; j < (number_of_rows - i); ++j) {
                        cout << ' ';
                    }
                    
                    // // go to the next row
                    // cout << endl;
                    cout << ' ';
                }
                cout << endl;
            }

            // bottom side of the figure K times:
            for (int i = (number_of_rows - 1); i > 0; --i) {
                for (int k = 0; k < cnt_of_figures; ++k) {
                    // 1st group of spaces
                    for (int j = 0; j < (number_of_rows - i); ++j) {
                        cout << ' ';
                    }

                    // stars
                    for (int j = 0; j < 1 + 2 * (i - 1); ++j) {
                        cout << '*';
                    }

                    // 2nd group of spaces
                    for (int j = 0; j < (number_of_rows - i); ++j) {
                        cout << ' ';
                    }
                    
                    // // go to the next row
                    // cout << endl;
                    cout << ' ';
                }
                cout << endl;
            }
            break;
    }
}
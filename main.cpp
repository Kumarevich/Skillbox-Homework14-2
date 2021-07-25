#include <iostream>

bool checking_fill(char arr[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (arr[i][j] == '_') {
                return false;
            }
        }
    }
    return true;
}

char checking_winer(char arr[3][3]) {
    char fail = 'F';
    for (int i = 0; i < 3; ++i) {
        if ((arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][i] != '_') ||
            (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[i][i] != '_')) {
            return arr[i][i];
        }
    }
    return fail;
}

bool checking_input(int line, int col, char a) {
    if (line > 0 && line < 4 && col > 0 && col < 4 &&  a == '_') {
        return true;
    }
    return false;
}

int main() {
    char tic_tac_toe[3][3] = {{ '_', '_', '_'},
                              { '_', '_', '_'},
                              { '_', '_', '_'}};
    char fail = 'F';
    char currentCh = 'X';
    int col, line;

    while (!checking_fill(tic_tac_toe) && checking_winer(tic_tac_toe) == fail) {
        std::cout << "Input the position (line, column) for " << currentCh << " char: ";
        std::cin >> line >> col;
        while (!checking_input(line, col, tic_tac_toe[line - 1][col - 1])) {
            std::cout << "Wrong input. Try again: ";
            std::cin >> line >> col;
        }

        tic_tac_toe[line - 1][col - 1] = currentCh;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << tic_tac_toe[i][j] << " ";
            }
            std::cout << std::endl;
        }

        if (currentCh == 'X') {
            currentCh = 'O';
        } else {
            currentCh = 'X';
        }
    }

    if (checking_fill(tic_tac_toe) && checking_winer(tic_tac_toe) == 'F') {
        std::cout << "Tie";
    } else {
        std::cout << "Winner: " << checking_winer(tic_tac_toe);
    }

    return 0;
}

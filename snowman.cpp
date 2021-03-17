#include "snowman.hpp"
#include <array>

using namespace ariel;
using namespace std;

const int PART_OF_BODY = 8;
const int OPTION = 4;
const int INPUT_SIZE = 8;
const int HAT = 0;
const int NOSE_MOUTH = 1;
const int LEFT_EYE = 2;
const int RIGHT_EYE = 3;
const int LEFT_ARM = 4;
const int RIGHT_ARM = 5;
const int TORSO = 6;
const int BASE = 7;
const int TEN = 10;
const int ZERO = 0;
const int FIRST_OPTION = 1;
const int LAST_OPTION = 4;

namespace ariel {
    array<int, INPUT_SIZE> build_input_array(int num) {
        int digit = ZERO;
        array<int, INPUT_SIZE> input_array = {};

        digit = num % TEN;
        input_array.at(BASE) = digit;
        num = num / TEN;

        digit = num % TEN;
        input_array.at(TORSO) = digit;
        num = num / TEN;

        digit = num % TEN;
        input_array.at(RIGHT_ARM) = digit;
        num = num / TEN;

        digit = num % TEN;
        input_array.at(LEFT_ARM) = digit;
        num = num / TEN;

        digit = num % TEN;
        input_array.at(RIGHT_EYE) = digit;
        num = num / TEN;

        digit = num % TEN;
        input_array.at(LEFT_EYE) = digit;
        num = num / TEN;

        digit = num % TEN;
        input_array.at(NOSE_MOUTH) = digit;
        num = num / TEN;

        digit = num % TEN;
        input_array.at(HAT) = digit;

        return input_array;
    }

    string addLeftHand(string snowman, array<int, INPUT_SIZE> input_array,
                       array<array<string, OPTION>, PART_OF_BODY> snowman_body_parts) {
        string left_arm_position;
        if (snowman_body_parts.at(LEFT_ARM).at(input_array.at(LEFT_ARM) - 1) == "\\") {
            left_arm_position += snowman_body_parts.at(HAT).at(input_array.at(HAT) - 1);
            snowman.replace(left_arm_position.size(), 1,
                            snowman_body_parts.at(LEFT_ARM).at(input_array.at(LEFT_ARM) - 1));
        } else {
            left_arm_position += snowman_body_parts.at(HAT).at(input_array.at(HAT) - 1) +
                                 snowman_body_parts.at(LEFT_EYE).at(input_array.at(LEFT_EYE) - 1) +
                                 snowman_body_parts.at(NOSE_MOUTH).at(input_array.at(NOSE_MOUTH) - 1) +
                                 snowman_body_parts.at(RIGHT_EYE).at(input_array.at(RIGHT_EYE) - 1);
            snowman.replace(left_arm_position.size(), 1,
                            snowman_body_parts.at(LEFT_ARM).at(input_array.at(LEFT_ARM) - 1));
        }
        return snowman;
    }

    string addRightHand(string snowman, array<int, INPUT_SIZE> input_array,
                        array<array<string, OPTION>, PART_OF_BODY> snowman_body_parts) {
        string right_arm_position;
        if (snowman_body_parts.at(RIGHT_ARM).at(input_array.at(RIGHT_ARM) - 1) == "/") {
            right_arm_position += snowman_body_parts.at(HAT).at(input_array.at(HAT) - 1) +
                                  snowman_body_parts.at(LEFT_EYE).at(input_array.at(LEFT_EYE) - 1) +
                                  snowman_body_parts.at(NOSE_MOUTH).at(input_array.at(NOSE_MOUTH) - 1) +
                                  snowman_body_parts.at(RIGHT_EYE).at(input_array.at(RIGHT_EYE) - 1);
            snowman.replace(right_arm_position.size() - 2, 1,
                            snowman_body_parts.at(RIGHT_ARM).at(input_array.at(RIGHT_ARM) - 1));
        } else {
            right_arm_position += snowman_body_parts.at(HAT).at(input_array.at(HAT) - 1) +
                                  snowman_body_parts.at(LEFT_EYE).at(input_array.at(LEFT_EYE) - 1) +
                                  snowman_body_parts.at(NOSE_MOUTH).at(input_array.at(NOSE_MOUTH) - 1) +
                                  snowman_body_parts.at(RIGHT_EYE).at(input_array.at(RIGHT_EYE) - 1) +
                                  snowman_body_parts.at(TORSO).at(input_array.at(TORSO) - 1);
            snowman.replace(right_arm_position.size() - 2, 1,
                            snowman_body_parts.at(RIGHT_ARM).at(input_array.at(RIGHT_ARM) - 1));
        }
        return snowman;
    }

    string snowman(int num) {
        int count = ZERO;
        int temp = num;
        int digit = ZERO;
        while (temp % TEN != ZERO) {
            digit = temp % TEN;
            temp = temp / TEN;
            if (digit < FIRST_OPTION || digit > LAST_OPTION) {
                throw invalid_argument("invalid input!");
            }
            count++;
        }
        if (count < INPUT_SIZE || count > INPUT_SIZE || num < ZERO) {
            throw invalid_argument("invalid input!");
        }
        string snowman;
        array<int, PART_OF_BODY> input_array = build_input_array(num);
        array<array<string, OPTION>, PART_OF_BODY> snowman_body_parts = {{
            {" _===_ \n", "  ___ \n"" .....\n", "   _  \n""  /_\\ \n", "  ___ \n"" (_*_) \n"},
            {",", ".", "_", " "},
            {" (.", " (o", " (O", " (-"},
            {".) \n", "o) \n", "O) \n", "-) \n"},
            {"<", "\\", "/", " "},
            {">", "/", "\\", " "},
            {" ( : ) \n", " (] [) \n", " (> <) \n", " (   ) \n"},
            {" ( : ) ", " (\" \") ", " (___) ", " (   ) "}
        }};
        snowman += snowman_body_parts.at(HAT).at(input_array.at(HAT) - 1) +
                   snowman_body_parts.at(LEFT_EYE).at(input_array.at(LEFT_EYE) - 1) +
                   snowman_body_parts.at(NOSE_MOUTH).at(input_array.at(NOSE_MOUTH) - 1) +
                   snowman_body_parts.at(RIGHT_EYE).at(input_array.at(RIGHT_EYE) - 1) +
                   snowman_body_parts.at(TORSO).at(input_array.at(TORSO) - 1) +
                   snowman_body_parts.at(BASE).at(input_array.at(BASE) - 1);
        snowman = addLeftHand(snowman, input_array, snowman_body_parts);
        snowman = addRightHand(snowman, input_array, snowman_body_parts);
        return snowman;
    }
}
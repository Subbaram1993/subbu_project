#include <stdio.h>
#include <assert.h>

// Declare the function implemented in the program
const char* number_to_words(int num);

void test_number_to_words() {
    assert(strcmp(number_to_words(123), "one hundred twenty-three") == 0);
    assert(strcmp(number_to_words(0), "zero") == 0);
    assert(strcmp(number_to_words(-45), "negative forty-five") == 0);
}

int main() {
    test_number_to_words();
    printf("All tests passed for numbers_to_word_conversion.c\n");
    return 0;
}

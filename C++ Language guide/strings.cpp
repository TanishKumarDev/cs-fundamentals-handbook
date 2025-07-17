#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::reverse
#include <unordered_set> // For duplicate detection
#include <cstring> // For C-style string functions
using namespace std;

// Function to print all substrings (used in Section 6)
void printSubstrings(const string& s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
            cout << s.substr(i, len) << " ";
        }
    }
    cout << endl;
}

// Function to find duplicate words in a vector of strings (Section 4.4)
void findDuplicates(const vector<string>& arr) {
    unordered_set<string> seen;
    unordered_set<string> duplicates;
    for (const auto& s : arr) {
        if (seen.find(s) != seen.end()) {
            duplicates.insert(s);
        } else {
            seen.insert(s);
        }
    }
    if (duplicates.empty()) {
        cout << "No duplicate words" << endl;
    } else {
        for (const auto& s : duplicates) {
            cout << s << " ";
        }
        cout << endl;
    }
}

int main() {
    // Section 1.1: Creating and Initializing Strings
    cout << "Section 1.1: Creating and Initializing Strings" << endl;
    string str = "Hello, World!";
    cout << str << endl; // Output: Hello, World!
    cout << "------------------------" << endl;

    // Section 1.2: Accessing String Characters
    cout << "Section 1.2: Accessing String Characters" << endl;
    string str_access = "Geek";
    cout << "Third character: " << str_access[2] << endl; // Output: e
    cout << "First character: " << str_access.at(0) << endl; // Output: G
    cout << "------------------------" << endl;

    // Section 1.3: Updating Strings
    cout << "Section 1.3: Updating Strings" << endl;
    string str_update = "Gueks";
    cout << "Original: " << str_update << endl; // Output: Gueks
    str_update[1] = 'e'; // Update second character
    cout << "Updated character: " << str_update << endl; // Output: Geeks
    str_update = "Geeky"; // Update entire string
    cout << "Updated string: " << str_update << endl; // Output: Geeky
    cout << "------------------------" << endl;

    // Section 1.4.1: Find Length of a String
    cout << "Section 1.4.1: Find Length of a String" << endl;
    string str_length = "GeeksforGeeks";
    cout << "Length: " << str_length.length() << endl; // Output: 13
    cout << "Size: " << str_length.size() << endl; // Output: 13
    cout << "------------------------" << endl;

    // Section 1.4.2: Take String as Input
    // Note: Commenting out interactive input to make the program deterministic
    /*
    cout << "Section 1.4.2: Take String as Input" << endl;
    string name;
    cout << "Enter your name: ";
    getline(cin, name); // Reads entire line, including spaces
    cout << "Hello, " << name << endl;
    */
    cout << "Section 1.4.2: Input (simulated)" << endl;
    string name = "John Doe"; // Simulated input
    cout << "Hello, " << name << endl; // Output: Hello, John Doe
    cout << "------------------------" << endl;

    // Section 1.4.3: Reverse a String
    cout << "Section 1.4.3: Reverse a String" << endl;
    string str_reverse = "Geeks";
    reverse(str_reverse.begin(), str_reverse.end());
    cout << "Reversed: " << str_reverse << endl; // Output: skeeG
    cout << "------------------------" << endl;

    // Section 1.4.4: String Concatenation
    cout << "Section 1.4.4: String Concatenation" << endl;
    string s1_concat = "Hello";
    string s2_concat = " World";
    // Using +
    string result1 = s1_concat + s2_concat;
    cout << "Using +: " << result1 << endl; // Output: Hello World
    // Using append
    s1_concat.append(s2_concat);
    cout << "Using append: " << s1_concat << endl; // Output: Hello World
    cout << "------------------------" << endl;

    // Section 1.4.5: Comparing Two Strings
    cout << "Section 1.4.5: Comparing Two Strings" << endl;
    string str1_compare = "apple";
    string str2_compare = "banana";
    // Using ==
    if (str1_compare == str2_compare) {
        cout << "Strings are equal" << endl;
    } else {
        cout << "Strings are not equal" << endl; // Output: Strings are not equal
    }
    // Using compare
    int result_compare = str1_compare.compare(str2_compare);
    if (result_compare == 0) {
        cout << "Strings are equal" << endl;
    } else if (result_compare < 0) {
        cout << "str1 comes before str2" << endl; // Output: str1 comes before str2
    } else {
        cout << "str1 comes after str2" << endl;
    }
    cout << "------------------------" << endl;

    // Section 1.4.6: Copying a String
    cout << "Section 1.4.6: Copying a String" << endl;
    string str1_copy = "Geeks";
    string str2_copy;
    // Using =
    str2_copy = str1_copy;
    cout << "Copied using =: " << str2_copy << endl; // Output: Geeks
    // Using assign
    str2_copy.assign("Geeky");
    cout << "Copied using assign: " << str2_copy << endl; // Output: Geeky
    cout << "------------------------" << endl;

    // Section 1.4.7: Find Substring
    cout << "Section 1.4.7: Find Substring" << endl;
    string str_find = "C++ Programming";
    size_t pos_find = str_find.find("Programming");
    if (pos_find != string::npos) {
        cout << "Found at position: " << pos_find << endl; // Output: Found at position: 4
    } else {
        cout << "Not found" << endl;
    }
    cout << "------------------------" << endl;

    // Section 1.4.8: Tokenizing a String
    cout << "Section 1.4.8: Tokenizing a String" << endl;
    string str_token = "Geeks,for,Geeks";
    string delimiter = ",";
    size_t pos_token = 0;
    string token;
    string str_token_copy = str_token; // Preserve original for tokenizing
    while ((pos_token = str_token_copy.find(delimiter)) != string::npos) {
        token = str_token_copy.substr(0, pos_token);
        cout << token << endl; // Output: Geeks, for
        str_token_copy.erase(0, pos_token + delimiter.length());
    }
    cout << str_token_copy << endl; // Output: Geeks
    cout << "------------------------" << endl;

    // Section 1.4.9: Passing Strings to Functions
    cout << "Section 1.4.9: Passing Strings to Functions" << endl;
    string s_pass = "GeeksforGeeks";
    cout << s_pass << endl; // Output: GeeksforGeeks
    cout << "------------------------" << endl;

    // Section 1.4.10: Modifying Strings
    cout << "Section 1.4.10: Modifying Strings" << endl;
    string str_modify = "I like dogs.";
    str_modify.insert(7, " black"); // Insert at position 7
    cout << "After insert: " << str_modify << endl; // Output: I like black dogs.
    str_modify.replace(7, 5, "cats"); // Replace "black" with "cats"
    cout << "After replace: " << str_modify << endl; // Output: I like cats dogs.
    str_modify.erase(6, 5); // Erase " cats"
    cout << "After erase: " << str_modify << endl; // Output: I like dogs.
    cout << "------------------------" << endl;

    // Section 1.4.11: Convert to C-Style String
    cout << "Section 1.4.11: Convert to C-Style String" << endl;
    string str_cstr = "C++";
    const char* cstr = str_cstr.c_str();
    cout << cstr << endl; // Output: C++
    cout << "------------------------" << endl;

    // Section 1.4.12: Substring
    cout << "Section 1.4.12: Substring" << endl;
    string s_substr = "Geeks";
    string sub = s_substr.substr(3, 2); // Extract "ks"
    cout << sub << endl; // Output: ks
    cout << "------------------------" << endl;

    // Section 2: C-Style Strings
    cout << "Section 2: C-Style Strings" << endl;
    char str_cstyle[] = "Hello";
    cout << str_cstyle << endl; // Output: Hello
    // C-Style String Concatenation
    char s1_cstyle[20] = "Hello"; // Must have enough space
    char s2_cstyle[] = " World";
    strcat(s1_cstyle, s2_cstyle);
    cout << s1_cstyle << endl; // Output: Hello World
    cout << "------------------------" << endl;

    // Section 3.1: Array of Strings
    cout << "Section 3.1: Array of Strings" << endl;
    string arr_strings[3] = {"This", "is", "array"};
    for (int i = 0; i < 3; i++) {
        cout << arr_strings[i] << " ";
    }
    cout << endl; // Output: This is array
    // Updating array of strings
    arr_strings[2] = "sparta";
    for (int i = 0; i < 3; i++) {
        cout << arr_strings[i] << " ";
    }
    cout << endl; // Output: This is sparta
    cout << "------------------------" << endl;

    // Section 3.2.1: Array of Pointers to C-Style Strings
    cout << "Section 3.2.1: Array of Pointers to C-Style Strings" << endl;
    const char* colours[4] = {"Blue", "Red", "Orange", "Yellow"};
    for (int i = 0; i < 4; i++) {
        cout << colours[i] << endl;
    }
    // Output:
    // Blue
    // Red
    // Orange
    // Yellow
    cout << "------------------------" << endl;

    // Section 3.2.2: 2D Array of Characters
    cout << "Section 3.2.2: 2D Array of Characters" << endl;
    char colours_2d[4][10] = {"Blue", "Red", "Orange", "Yellow"};
    for (int i = 0; i < 4; i++) {
        cout << colours_2d[i] << endl;
    }
    // Output:
    // Blue
    // Red
    // Orange
    // Yellow
    cout << "------------------------" << endl;

    // Section 3.3: Vector of Strings
    cout << "Section 3.3: Vector of Strings" << endl;
    vector<string> v_strings = {"This", "is", "vector"};
    v_strings.push_back("container");
    for (const auto& s : v_strings) {
        cout << s << " ";
    }
    cout << endl; // Output: This is vector container
    cout << "------------------------" << endl;

    // Section 4.1: Get Substring Before/After a Character
    cout << "Section 4.1: Get Substring Before/After a Character" << endl;
    // Before a Character
    string s_before = "dog:cat";
    size_t pos_before = s_before.find(":");
    string sub_before = s_before.substr(0, pos_before);
    cout << "Substring before ':': " << sub_before << endl; // Output: dog
    // After a Character
    string sub_after = s_before.substr(pos_before + 1);
    cout << "Substring after ':': " << sub_after << endl; // Output: cat
    cout << "------------------------" << endl;

    // Section 4.2: Print All Substrings
    cout << "Section 4.2: Print All Substrings" << endl;
    string s_allsub = "abcd";
    for (int i = 0; i < s_allsub.length(); i++) {
        for (int len = 1; len <= s_allsub.length() - i; len++) {
            cout << s_allsub.substr(i, len) << endl;
        }
    }
    // Output:
    // a
    // ab
    // abc
    // abcd
    // b
    // bc
    // bcd
    // c
    // cd
    // d
    cout << "------------------------" << endl;

    // Section 4.3: Sum of All Substrings (Numeric String)
    cout << "Section 4.3: Sum of All Substrings (Numeric String)" << endl;
    string s_num = "1234";
    int res = 0;
    int n = s_num.length();
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
            string sub_num = s_num.substr(i, len);
            res += stoi(sub_num);
        }
    }
    cout << "Sum of substrings: " << res << endl; // Output: 1670
    cout << "------------------------" << endl;

    // Section 4.4: Find and Print Duplicate Words in a Vector of Strings
    cout << "Section 4.4: Find Duplicate Words" << endl;
    vector<string> arr_duplicates = {"welcome", "to", "geeks", "for", "geeks"};
    findDuplicates(arr_duplicates); // Output: geeks
    cout << "------------------------" << endl;

    return 0;
}
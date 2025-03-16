#include "ladder.h"
/* 

int main() {
    set<string> dictionary;
    string filename = "src/words.txt";  // Adjust this to your actual dictionary file path

    // Load words from file
    load_words(dictionary, filename);

    // Print the number of words loaded
    cout << "Number of words loaded: " << dictionary.size() << endl;

    // Print first 10 words to verify loading
    int count = 0;
    for (const auto &word : dictionary) {
        cout << word << endl;
        if (++count >= 10) break;  // Limit to first 10 words
    }

    return 0;
}
*/



//Adjacent tests
int main() {
    // Test cases
    string word1, word2;

    // Manual tests
    cout << "Enter two words to check adjacency: ";
    cin >> word1 >> word2;
    
    if (is_adjacent(word1, word2)) {
        cout << word1 << " and " << word2 << " are adjacent (differ by 1 letter)." << endl;
    } else {
        cout << word1 << " and " << word2 << " are NOT adjacent." << endl;
    }

    // Additional automated tests
    cout << "\nAutomated Test Cases:" << endl;
    cout << "hit -> hot: " << (is_adjacent("hit", "hot") ? "True" : "False") << endl;
    cout << "hot -> dot: " << (is_adjacent("hot", "dot") ? "True" : "False") << endl;
    cout << "dot -> dog: " << (is_adjacent("dot", "dog") ? "True" : "False") << endl;
    cout << "dog -> dig: " << (is_adjacent("dog", "dig") ? "True" : "False") << endl;
    cout << "dog -> cat: " << (is_adjacent("dog", "cat") ? "True" : "False") << endl;
    cout << "apple -> apply: " << (is_adjacent("apple", "apply") ? "True" : "False") << endl;

    return 0;
}


/*

int main() {
    set<string> words;
    load_words(words, "src/words.txt");

    string start, end;
    cout << "Enter start word: ";
    cin >> start;
    cout << "Enter end word: ";
    cin >> end;

    vector<string> ladder = generate_word_ladder(start, end, words);

    if (ladder.empty()) {
        cout << "No word ladder found!" << endl;
    } else {
        cout << "Word Ladder: ";
        for (const string& word : ladder) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

*/
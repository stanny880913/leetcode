    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    // char nextGreatestLetter(vector<char> &letters, char target)
    // {
    //     for (int i = 0; i < letters.size(); i++)
    //     {
    //         if(letters[i] > target)
    //             return letters[i];
    //     }
    //     return letters[0];
    // }
    char nextGreatestLetter(vector<char> &letters, char target)
    {

        int left = 0;
        int right = letters.size() - 1;
        int mid;

        while (left < right)
        {
            mid = (left + right) / 2;
            if (letters[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        if(left == letters.size())
            return letters[0];
        else    
            return letters[left];;
    }

    int main()
    {
        vector<char> letters = {'c', 'f', 'j'};
        char target = 'a';
        nextGreatestLetter(letters, target);
        return 0;
    }
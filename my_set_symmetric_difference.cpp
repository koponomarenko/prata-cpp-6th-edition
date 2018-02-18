#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <chrono>
#include <random>


// based on std::set_symmetric_difference
template<typename InputIterator1, typename InputIterator2, typename OutputIterator> OutputIterator 
set_symmetric_difference_with_duplicates(InputIterator1 first1, InputIterator1 last1,
                                         InputIterator2 first2, InputIterator2 last2,
                                         OutputIterator result)
{
    typename InputIterator1::value_type found_duplicate;

    while (first1 != last1 && first2 != last2)
    {
        if (*first1 < *first2)
        {
            *result = *first1;
            ++first1;
            ++result;
        }
        else if (*first2 < *first1)
        {
            *result = *first2;
            ++first2;
            ++result;
        }
        else
        {
            found_duplicate = *first1;

            do {
                ++first1;
            } while (first1 != last1 && *first1 == found_duplicate);
            do {
                ++first2;
            } while (first2 != last2 && *first2 == found_duplicate);
        }
    }

    return std::copy(first2, last2, std::copy(first1, last1, result));
}

std::set<int> 
getUniqueNumbers(const int arr1[], const int arr1Size, const int arr2[], const int arr2Size)
{
    std::set<int> set1 (arr1, arr1 + arr1Size); // O(n*log(n))
    std::set<int> set2 (arr2, arr2 + arr2Size); // O(n*log(n))
    std::set<int> uniqueNumbers;

    std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), 
                                  std::inserter(uniqueNumbers, uniqueNumbers.end())); // O(n)

    return uniqueNumbers;
}

std::vector<int> 
getUniqueNumbersWithDuplicates1(const int arr1[], const int arr1Size, const int arr2[], const int arr2Size)
{
    std::multiset<int> set1 (arr1, arr1 + arr1Size); // O(n*log(n))
    std::multiset<int> set2 (arr2, arr2 + arr2Size); // O(n*log(n))
    std::vector<int> uniqueNumbers;

    set_symmetric_difference_with_duplicates(set1.begin(), set1.end(), set2.begin(), set2.end(), 
                                             std::back_inserter(uniqueNumbers)); // O(n)

    return uniqueNumbers;
}

std::multiset<int>
getUniqueNumbersWithDuplicates2(const int arr1[], const int arr1Size, const int arr2[], const int arr2Size)
{
    std::multiset<int> set1 (arr1, arr1 + arr1Size); // O(n*log(n))
    std::multiset<int> set2 (arr2, arr2 + arr2Size); // O(n*log(n))
    std::multiset<int> uniqueNumbers;

    set_symmetric_difference_with_duplicates(set1.begin(), set1.end(), set2.begin(), set2.end(), 
                                             std::inserter(uniqueNumbers, uniqueNumbers.end())); // O(n)

    return uniqueNumbers;
}

std::unordered_multiset<int> 
getUniqueNumbersWithDuplicates3(const int arr1[], const int arr1Size, const int arr2[], const int arr2Size)
{
    std::unordered_multiset<int> uniqueNumbers(arr1, arr1 + arr1Size); // O(n)
    std::unordered_multiset<int> tmpSet(arr2, arr2 + arr2Size); // O(n)

    for (auto it = tmpSet.begin(); it != tmpSet.end(); ) // O(n)
    {
        auto tmpSetRange = tmpSet.equal_range(*it);

        auto range = uniqueNumbers.equal_range(*it);
        if (range.first != range.second) // element is found
        {
            uniqueNumbers.erase(range.first, range.second);
        }
        else
        {
            uniqueNumbers.insert(tmpSetRange.first, tmpSetRange.second);
        }

        it = tmpSetRange.second;
    }

    return uniqueNumbers;
}

std::unordered_multiset<int> 
getUniqueNumbersWithDuplicates4(const int arr1[], const int arr1Size, const int arr2[], const int arr2Size)
{
    std::unordered_multiset<int> set1(arr1, arr1 + arr1Size); // O(n)
    std::unordered_multiset<int> set2(arr2, arr2 + arr2Size); // O(n)
    std::unordered_multiset<int> uniqueNumbers;

    // look in set1
    for (auto it = set1.begin(); it != set1.end(); ) // O(n)
    {
        auto set1Range = set1.equal_range(*it);

        if (set2.find(*it) == set2.end())
        {
            uniqueNumbers.insert(set1Range.first, set1Range.second);
        }

        it = set1Range.second;
    }

    // look in set2
    for (auto it = set2.begin(); it != set2.end(); ) // O(n)
    {
        auto set2Range = set2.equal_range(*it);

        if (set1.find(*it) == set1.end())
        {
            uniqueNumbers.insert(set2Range.first, set2Range.second);
        }

        it = set2Range.second;
    }

    return uniqueNumbers;
}

int main()
{
    //int arr1[] = {1, 3, 3, 3, 5};
    //int arr2[] = {1, 2, 4, 5};

    // { 1, 2, 2 }, {2, 3, 3} -> {1, 3, 3}
    //int arr1[] = {1, 2, 2};
    //int arr2[] = {2, 3, 3};

    //int arr1[] = {1, 2, 1, 2};
    //int arr2[] = {2, 3, 3};

    //int arr1Size = sizeof(arr1) / sizeof(arr1[0]);
    //int arr2Size = sizeof(arr2) / sizeof(arr2[0]);

    const int arr1Size = 1000000;
    const int arr2Size = 1000000;
    std::cout << "arr size: " << arr1Size << std::endl;

    int * arr1 = new int[arr1Size];
    int * arr2 = new int[arr2Size];

    std::default_random_engine randEng((std::random_device())());
    //int randMax = std::numeric_limits<int>::max();
    //int randMax = arr1Size / 10;
    int randMax = arr1Size;
    std::uniform_int_distribution<int> uniformDist(0, randMax);
    std::cout << "rand max: " << randMax << std::endl;
    for (int i = 0; i < arr1Size; ++i)
        arr1[i] = uniformDist(randEng);

    for (int i = 0; i < arr2Size; ++i)
        arr2[i] = uniformDist(randEng);


    // v1 - vector
    auto start = std::chrono::system_clock::now();

    std::vector<int> uniqueNumbers1 = getUniqueNumbersWithDuplicates1(arr1, arr1Size, arr2, arr2Size);

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start);
    std::cout << "v1 duration: " << duration.count() << std::endl;
    std::cout << "v1 final size: " << uniqueNumbers1.size() << std::endl;
/*
    std::cout << "v1 result: " << std::endl;
    for (auto & i : uniqueNumbers)
        std::cout << i << " ";
    std::cout << std::endl << std::endl;
*/

    // v2 - multiset
    start = std::chrono::system_clock::now();

    std::multiset<int> uniqueNumbers2 = getUniqueNumbersWithDuplicates2(arr1, arr1Size, arr2, arr2Size);

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start);
    std::cout << "v2 duration: " << duration.count() << std::endl;
    std::cout << "v2 final size: " << uniqueNumbers2.size() << std::endl;
/*
    std::cout << "v2 result: " << std::endl;
    for (auto & i : uniqueNumbers2)
        std::cout << i << " ";
    std::cout << std::endl << std::endl;
*/

    // v3 - unordered_multiset, in-place removal, uses less memory, but spend time "erasing"
    start = std::chrono::system_clock::now();

    std::unordered_multiset<int> uniqueNumbers3 = getUniqueNumbersWithDuplicates3(arr1, arr1Size, arr2, arr2Size);

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start);
    std::cout << "v3 duration: " << duration.count() << std::endl;
    std::cout << "v3 final size: " << uniqueNumbers3.size() << std::endl;
/*
    std::cout << "v3 result: " << std::endl;
    for (auto & i : uniqueNumbers3)
        std::cout << i << " ";
    std::cout << std::endl << std::endl;
*/

    // v4 - unordered_multiset, with 3rd resulting set, uses more memory, but no "erasing" time
    start = std::chrono::system_clock::now();

    std::unordered_multiset<int> uniqueNumbers4 = getUniqueNumbersWithDuplicates4(arr1, arr1Size, arr2, arr2Size);

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start);
    std::cout << "v4 duration: " << duration.count() << std::endl;
    std::cout << "v4 final size: " << uniqueNumbers4.size() << std::endl;
/*
    std::cout << "v4 result: " << std::endl;
    for (auto & i : uniqueNumbers4)
        std::cout << i << " ";
    std::cout << std::endl << std::endl;
*/
    delete [] arr1;
    delete [] arr2;
}

#include <iostream>
#include <vector>


// Split

/*
    function ListNode sortList(ListNode head)
    {
        + This is in case i have only one 1 item or 0 item.
        if (head == NULL || head.next == NULL)
            return head;

        + Here we need to get a refrence to the middle node.
        mid = size(head) / 2;

        ListNode leftSorted =  sortList(head);
        ListNode rightSorted = sortlist(mid);

        return merge(leftSorted, rightSorted);
    }

*/



// Merge

// int *merge(int *leftArray, int *rightArray)
// {
//     // This merger function must be using insertion sort.
// }

void    printVector(std::vector<int> input);
void    insertionSort(std::vector<int>& input);
std::vector<int> mergeSort(std::vector<int> input);

std::vector<int> merge(std::vector<int> leftArray, std::vector<int> rightArray)
{
    std::vector<int>::iterator i;
    std::vector<int>::iterator j;
    std::vector<int> result;


    i = leftArray.begin();
    j = rightArray.begin();

    while (i != leftArray.end() && j != rightArray.end())
    {
        if (*i <= *j)
        {
            result.push_back(*i);
            i++;
        }
        else
        {
            result.push_back(*j);
            j++;
        }
    }
    while (i != leftArray.end())
    {
        result.push_back(*i);
        i++;
    }
    while (j != rightArray.end())
    {
        result.push_back(*j);
        j++;
    }
    return (result);
}

void insertionSort(std::vector<int>& input)
{
    for (int i = 1; i < input.size(); i++)
    {
        int key = input[i];
        int j = i - 1;
        while (j >= 0 && input[j] > key)
        {
            input[j + 1] = input[j];
            j--;
        }
        input[j + 1] = key;
    }
}


std::vector<int> mergeSort(std::vector<int> input)
{
    // std::cout << "Size: " << input.size() << std::endl;
    std::vector<int>::iterator middle;

    if (input.size() == 1)
        return input;
    // if (input.size() <= 2) // Use insertion sort for small subarrays with a threshold of 2
    // {
    //     insertionSort(input);
    //     return input;
    // }

    middle = input.begin() + input.size() / 2;

    std::vector<int> leftVector =  mergeSort(std::vector<int>(input.begin(), middle));
    std::vector<int> rightVector = mergeSort(std::vector<int>(middle, input.end()));
    return merge(leftVector, rightVector);
}


void    printVector(std::vector<int> input)
{
     std::vector<int>::iterator print;

    print = input.begin();

    while (print != input.end())
    {
        std::cout << *print << " ";
        print++; 
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<int> data = {9, 14, 4, 6, 5, 8, 7};
    std::vector<int> result = mergeSort(data);

    printVector(result);
    return (0);
}
#include <iostream>
#include <time.h>
#include <ctime>
#include <vector>
#include <typeinfo>
#include <fstream>
using namespace std;

void Sort(vector<int> &operationsSelection, vector<int> &operationsInsertion,
        vector<int> &operationsBubble, vector<int> list, int runCount,
        vector<double> &selectionTimes, vector<double> &bubbleTimes,
        vector<double> &insertionTimes);
void PrintArray(vector<double> list);
int InsertionSort(vector<int> list, vector<int> &operationsTemp);
int BubbleSort(vector<int> list, vector<int> &operationsTemp);
int SelectionSort(vector<int> list, vector<int> &operationsTemp);
double Average(vector<double> list);
int LinearSearchArray(vector<int> list, int target);
void GenerateVectors(char input, vector<int> &vec500,vector<int> &vec1000,
                    vector<int> &vec5000,vector<int> &vec10000);

// main()
int main(){
    clock_t timerTotal;
    int runCount = 5;
    vector<int> vec500(0);
    vector<int> vec1000(0);
    vector<int> vec5000(0);
    vector<int> vec10000(0);
    vector<int> operationsSelection(0);
    vector<int> operationsInsertion(0);
    vector<int> operationsBubble(0);
    vector<double> selectionTimes(0);
    vector<double> bubbleTimes(0);
    vector<double> insertionTimes(0);
    ofstream selectionFile;
    ofstream insertionFile;
    ofstream bubbleFile;

    selectionFile.open("selection_sort_results.csv");
    insertionFile.open("insertion_sort_results.csv");
    bubbleFile.open("bubble_sort_results.csv");

    selectionFile << "Vector configuration,Seconds,# Data Comparisons,# Loop Comparisons,"
                    << "# Data Assignments,# Loop Assignments,# Other, # Total\n";
    insertionFile << "Vector configuration,Seconds,# Data Comparisons,# Loop Comparisons,"
                    << "# Data Assignments,# Loop Assignments,# Other, # Total\n";
    bubbleFile << "Vector configuration,Seconds,# Data Comparisons,# Loop Comparisons,"
                    << "# Data Assignments,# Loop Assignments,# Other, # Total\n";
    timerTotal = (double)clock()/CLOCKS_PER_SEC;
    //Opens all files and writes initial column labels to each

    cout << "\n-----===== Un-Sorted vectors (random) =====-----";
    GenerateVectors('r', vec500, vec1000, vec5000, vec10000);
    Sort(operationsSelection, operationsInsertion, operationsBubble, vec500, runCount,
        selectionTimes, insertionTimes, bubbleTimes);
    Sort(operationsSelection, operationsInsertion, operationsBubble, vec1000, runCount,
        selectionTimes, insertionTimes, bubbleTimes);
    Sort(operationsSelection, operationsInsertion, operationsBubble, vec5000, runCount,
        selectionTimes, insertionTimes, bubbleTimes);
    Sort(operationsSelection, operationsInsertion, operationsBubble, vec10000, runCount,
        selectionTimes, insertionTimes, bubbleTimes);
    //Runs all randomly sorted vector sizes against all 3 algorithms, returning run times 
    //and operation counts appended to original vectors

    cout << "\n-----===== Pre-Sorted vectors (ascending) =====-----";
    GenerateVectors('a', vec500, vec1000, vec5000, vec10000);
    Sort(operationsSelection, operationsInsertion, operationsBubble, vec500, runCount,
        selectionTimes, insertionTimes, bubbleTimes);
    Sort(operationsSelection, operationsInsertion, operationsBubble, vec1000, runCount,
        selectionTimes, insertionTimes, bubbleTimes);
    Sort(operationsSelection, operationsInsertion, operationsBubble, vec5000, runCount,
        selectionTimes, insertionTimes, bubbleTimes);
    Sort(operationsSelection, operationsInsertion, operationsBubble, vec10000, runCount,
        selectionTimes, insertionTimes, bubbleTimes);
    //Runs all ascending sorted vector sizes against all 3 algorithms, returning run times 
    //and operation counts appended to original vectors

    cout << "\n-----===== Pre-Sorted vectors (descending) =====-----";
    GenerateVectors('d', vec500, vec1000, vec5000, vec10000);
    Sort(operationsSelection, operationsInsertion, operationsBubble, vec500, runCount, selectionTimes, insertionTimes, bubbleTimes);
    Sort(operationsSelection, operationsInsertion, operationsBubble, vec1000, runCount, selectionTimes, insertionTimes, bubbleTimes);
    Sort(operationsSelection, operationsInsertion, operationsBubble, vec5000, runCount, selectionTimes, insertionTimes, bubbleTimes);
    Sort(operationsSelection, operationsInsertion, operationsBubble, vec10000, runCount, selectionTimes, insertionTimes, bubbleTimes);
    //Runs all descending sorted vector sizes against all 3 algorithms, returning run times 
    //and operation counts appended to original vectors


    for(int i = 0; i < 12; i++){
        switch(i){
            case 0:
            selectionFile << "Random N=500,";
            insertionFile << "Random N=500,";
            bubbleFile << "Random N=500,";
            break;
            case 1:
            selectionFile << "Random N=1000,";
            insertionFile << "Random N=1000,";
            bubbleFile << "Random N=1000,";
            break;
            case 2:
            selectionFile << "Random N=5000,";
            insertionFile << "Random N=5000,";
            bubbleFile << "Random N=5000,";
            break;
            case 3:
            selectionFile << "Random N=10000,";
            insertionFile << "Random N=10000,";
            bubbleFile << "Random N=10000,";
            break;
            case 4:
            selectionFile << "Sorted N=500,";
            insertionFile << "Sorted N=500,";
            bubbleFile << "Sorted N=500,";
            break;
            case 5:
            selectionFile << "Sorted N=1000,";
            insertionFile << "Sorted N=1000,";
            bubbleFile << "Sorted N=1000,";
            break;
            case 6:
            selectionFile << "Sorted N=5000,";
            insertionFile << "Sorted N=5000,";
            bubbleFile << "Sorted N=5000,";
            break;
            case 7:
            selectionFile << "Sorted N=10000,";
            insertionFile << "Sorted N=10000,";
            bubbleFile << "Sorted N=10000,";
            break;
            case 8:
            selectionFile << "Sorted N=500,";
            insertionFile << "Sorted N=500,";
            bubbleFile << "Sorted N=500,";
            break;
            case 9:
            selectionFile << "Sorted N=1000,";
            insertionFile << "Sorted N=1000,";
            bubbleFile << "Sorted N=1000,";
            break;
            case 10:
            selectionFile << "Sorted N=5000,";
            insertionFile << "Sorted N=5000,";
            bubbleFile << "Sorted N=5000,";
            break;
            case 11:
            selectionFile << "Sorted N=10000,";
            insertionFile << "Sorted N=10000,";
            bubbleFile << "Sorted N=10000,";
            break;
        }
        //Writes row label to each file based on the current line as indicated by 'i'

        selectionFile << selectionTimes.at(i) << ',';
        insertionFile << insertionTimes.at(i) << ',';
        bubbleFile << bubbleTimes.at(i) << ',';
        //Writes relevant average trial run time for each file/sorting algorithm

        for(int j = 0; j < 6; j++){
            selectionFile << operationsSelection.at((j+i*6)) << ',';
            insertionFile << operationsInsertion.at((j+i*6)) << ',';
            bubbleFile << operationsBubble.at((j+i*6)) << ',';
            //For each line, write the next six operation counts to each file
        }
        selectionFile << '\n';
        insertionFile << '\n';
        bubbleFile << '\n';
    }
    selectionFile.close();
    insertionFile.close();
    bubbleFile.close();

    cout << "\nTotal runtime: " << (double)clock()/CLOCKS_PER_SEC - timerTotal << " seconds\n";
}
//===========================================================================================



//Takes and outputs the average of a vector
double Average(vector<double> list){
    double sum;
    double average;
    for(int i = 0; i < list.size(); i++){
        sum += list.at(i);
    }
    average = sum/list.size();
    return average;
}
//===========================================================================================



/*
Sorts each vector runCount times, and appends average run times and operation counts
to output vectors. Outputs progress to console.
*/
void Sort(vector<int> &operationsSelection,
        vector<int> &operationsInsertion,
        vector<int> &operationsBubble,
        vector<int> list,
        int runCount,
        vector<double> &selectionTimes,
        vector<double> &insertionTimes,
        vector<double> &bubbleTimes){
        //Appends outputs for each operation count type and average run times to
        //relevant output vectors
    int count;
    clock_t timer;
    srand(time(NULL));
    vector<double> times(0);
    vector<int> operationsTemp(0);

    cout << "\nSorting size " << list.size() << " vectors\n";

    cout << "Running selection sorts: [0/" << runCount << "]" << flush;
    for(int i = 0; i < runCount; i++){
        timer = (double)clock()/CLOCKS_PER_SEC;
        count = SelectionSort(list, operationsTemp);
        times.push_back((double)clock()/CLOCKS_PER_SEC - timer);
        cout << "\rRunning selection sorts: [" << i+1 << "/" << runCount << "]" << flush;
    }
    selectionTimes.push_back(Average(times));
    cout << ' ' << count << " operations, " << Average(times) << "s/trial average" << endl;
    operationsSelection.insert(operationsSelection.end(), operationsTemp.begin(), operationsTemp.end());
    //Runs selection sort against input vector runCount times, timing how long it takes to
    //run and appending it to vector 'times'. Finds and appends average time to relevant
    //output vector, as well as appends most recent set of operation counts to overall
    //selection sort counter (all operation count sets for a given vector will be the same)

    times = {};
    //Resets temp variables
    cout << "Running insertion sorts: [0/" << runCount << "]" << flush;
    for(int i = 0; i < runCount; i++){
        timer = (double)clock()/CLOCKS_PER_SEC;
        count = InsertionSort(list, operationsTemp);
        times.push_back((double)clock()/CLOCKS_PER_SEC - timer);
        cout << "\rRunning insertion sorts: [" << i+1 << "/" << runCount << "]" << flush;
    }
    insertionTimes.push_back(Average(times));
    cout << ' ' << count << " operations, " << Average(times) << "s/trial average" << endl;
    operationsInsertion.insert(operationsInsertion.end(), operationsTemp.begin(), operationsTemp.end());
    //Runs insertion sort against input vector runCount times, timing how long it takes to
    //run and appending it to vector 'times'. Finds and appends average time to relevant
    //output vector, as well as appends most recent set of operation counts to overall
    //insertion sort counter (all operation count sets for a given vector will be the same)

    times = {};
    //Resets temp variables
    cout << "Running bubble sorts:    [0/" << runCount << "]" << flush;
    for(int i = 0; i < runCount; i++){
        timer = (double)clock()/CLOCKS_PER_SEC;
        count = BubbleSort(list, operationsTemp);
        times.push_back((double)clock()/CLOCKS_PER_SEC - timer);
        cout << "\rRunning bubble sorts:    [" << i+1 << "/" << runCount << "]" << flush;
    }
    bubbleTimes.push_back(Average(times));
    cout << ' ' << count << " operations, " << Average(times) << "s/trial average" << endl;
    operationsBubble.insert(operationsBubble.end(), operationsTemp.begin(), operationsTemp.end());
    //Runs bubble sort against input vector runCount times, timing how long it takes to
    //run and appending it to vector 'times'. Finds and appends average time to relevant
    //output vector, as well as appends most recent set of operation counts to overall
    //bubble sort counter (all operation count sets for a given vector will be the same)
}
//===========================================================================================



//Sorts input array using insertion sort algorithm and outputs operation counts
int InsertionSort(vector<int> list, vector<int> &operationsTemp){
    int dataCompares = 0;
    int loopCompares = 0;
    int dataOps = 0;
    int loopOps = 0;
    int otherOps = 0;
    int totalOps = 0;
    int i, j, sel; 

    operationsTemp = {};

    loopOps++;
    for(i = 1; i < list.size(); i++){
        loopCompares++;
        sel = list.at(i);
        dataOps++;
        j = i-1;
        loopOps++;
        while((j >= 0) && (sel < list.at(j))){
            loopCompares += 2;
            list.at(j+1) = list.at(j);
            dataOps++;
            j--;
            loopOps++;
        }
        loopCompares += 2;
        list.at(j+1) = sel;
        dataOps++;
        loopOps++;
    }
    loopCompares++;
    totalOps = dataCompares+loopCompares+dataOps+loopOps+otherOps;
    operationsTemp.push_back(dataCompares);
    operationsTemp.push_back(loopCompares);
    operationsTemp.push_back(dataOps);
    operationsTemp.push_back(loopOps);
    operationsTemp.push_back(otherOps);
    operationsTemp.push_back(totalOps);
    return totalOps;
}
//===========================================================================================



//Sorts input array using bubble sort algorithm and outputs operation counts
int BubbleSort(vector<int> list, vector<int> &operationsTemp){
    int dataCompares = 0;
    int loopCompares = 0;
    int dataOps = 0;
    int loopOps = 0;
    int otherOps = 0;
    int totalOps = 0;
    int buffer;
    bool sorting;

    operationsTemp = {};

    do{
        sorting = false;
        loopOps++;

        loopOps++;
        for(int i = 0; i < list.size()-1; i++){
            loopCompares++;
            if(list.at(i) > list.at(i+1)){
                buffer = list.at(i);
                list.at(i) = list.at(i+1);
                list.at(i+1) = buffer;
                dataOps++;
                sorting = true;
                loopOps++;
            }
            dataCompares++;
            loopOps++;
        }
        loopCompares++;

        loopCompares++;
    } while(sorting == true);

    totalOps = dataCompares+loopCompares+dataOps+loopOps+otherOps;

    operationsTemp.push_back(dataCompares);
    operationsTemp.push_back(loopCompares);
    operationsTemp.push_back(dataOps);
    operationsTemp.push_back(loopOps);
    operationsTemp.push_back(otherOps);
    operationsTemp.push_back(totalOps);
    return totalOps;
}
//===========================================================================================



//Sorts input array using selection sort algorithm and outputs operation counts
int SelectionSort(vector<int> list, vector<int> &operationsTemp){
    int dataCompares = 0;
    int loopCompares = 0;
    int dataOps = 0;
    int loopOps = 0;
    int otherOps = 0;
    int totalOps = 0;
    int buffer;
    int lowest;
    int iterations = 0;

    operationsTemp = {};

    loopOps++;
    for(int j = 0; j < list.size()-1; j++){
        lowest = iterations;
        dataOps++;
        loopCompares++;

        loopOps++;
        for(int i = 1+iterations; i < list.size(); i++){
            loopCompares++;
            if(list.at(i) < list.at(lowest)){
                lowest = i;
                dataOps++;
            }
            dataCompares++;
            loopOps++;
        }
        loopCompares++;
        buffer = list.at(lowest);
        list.erase(list.begin()+lowest);
        list.insert(list.begin()+iterations,buffer);
        dataOps += 3;
        iterations++;
        loopOps += 2;
    }
    loopCompares++;
    totalOps = dataCompares+loopCompares+dataOps+loopOps+otherOps;
    operationsTemp.push_back(dataCompares);
    operationsTemp.push_back(loopCompares);
    operationsTemp.push_back(dataOps);
    operationsTemp.push_back(loopOps);
    operationsTemp.push_back(otherOps);
    operationsTemp.push_back(totalOps);
    return totalOps;
}
//===========================================================================================



//
void PrintArray(vector<double> list){
    for(int i = 0; i < list.size(); i++){
        if(i<list.size()-1){
            cout << list.at(i) << ", ";
        } else{
            cout << list.at(i) << '\n';
        }
    }
}



/*
Generates 500 long, 1000 long, 5000 long, and 10000 long vectors either randomly sorted,
sorted ascending, or sorted descending depending on if the input was 'r', 'a', or 'd'
*/
void GenerateVectors(char input, vector<int> &vec500,vector<int> &vec1000,vector<int> &vec5000,vector<int> &vec10000){
    vec500 = {};
    vec1000 = {};
    vec5000 = {};
    vec10000 = {};
    if(input == 'r'){
        for(int i = 0; i < 500; i++){
            vec500.push_back(rand()%500);
        }
        for(int i = 0; i < 1000; i++){
            vec1000.push_back(rand()%1000);
        }
        for(int i = 0; i < 5000; i++){
            vec5000.push_back(rand()%5000);
        }
        for(int i = 0; i < 10000; i++){
            vec10000.push_back(rand()%10000);
        }
    } else if(input == 'a'){
        for(int i = 0; i < 500; i++){
            vec500.push_back(i+1);
        }
        for(int i = 0; i < 1000; i++){
            vec1000.push_back(i+1);
        }
        for(int i = 0; i < 5000; i++){
            vec5000.push_back(i+1);
        }
        for(int i = 0; i < 10000; i++){
            vec10000.push_back(i+1);
        }
    } else if(input == 'd'){
        for(int i = 500; i > 0; i--){
            vec500.push_back(i);
        }
        for(int i = 1000; i > 0; i--){
            vec1000.push_back(i);
        }
        for(int i = 5000; i > 0; i--){
            vec5000.push_back(i);
        }
        for(int i = 10000; i > 0; i--){
            vec10000.push_back(i);
        }
    } else{
        cout << "Vector generation error!\n";
        exit(-1);
    }
}
//===========================================================================================

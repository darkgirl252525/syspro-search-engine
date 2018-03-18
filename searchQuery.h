#ifndef _SEARCHQUERY_H_
#define _SEARCHQUERY_H_

#include "invertedIndex.h"
#include "index.h"

typedef struct scoreNode{
	int id;
	char* words;
	double score;
}scoreNode;

typedef struct scores{
	int size;
	int actualSize;
	scoreNode* scoreArray;
}scores;

void printMaxKScores(scores* scoresArray,mapIndex* index,int K);
void printAlteredOutput(scoreNode* scoreArray,mapIndex* index,ssize_t bufSize);
void calculateScoresWord(rootNode* root,char* word,generalInfo* info,scores* scoresArray,mapIndex* index);
void insertEachPostNode(scores* scoresArray,trieNode* node,generalInfo* info,mapIndex* index,char* word);
double calculateScore(generalInfo* info,int docFrequency,postingLists* node,mapIndex* index);
int binarySearchScores(scores* scoresArray, int id);
void insertionSortScores(scores* scoresArray, scoreNode* insertNode);
void printScoresArray(scores* scoresArray);
void copyDataScore(scoreNode* oldNode,scoreNode* newNode);
void heapify(scores* scoresArray, int n, int i);
void buildHeap(scores* scoresArray);
void heapSort(scores* scoresArray);
void printSpaces(int spaces);
void printSpecialChars(int lengthWord);
void printDividedLines(char* source,int documentLength,int partLength,scoreNode* scoreArray,int bufSize);

//funcs for nodes
scores* createScoresArray();
void doubleScoresArray(scores* scoresArray);
void destroyScoresArray(scores** scoresArray);

#endif
#include <stdio.h>
#include <stdlib.h>

// RecordType
struct RecordType
{
	int		id;
	char	name;
	int		order; 
};

struct ListNode {
    struct RecordType data;
    struct ListNode* next;
};

// Fill out this structure
struct HashType
{
	struct ListNode** table;
	int size;
};

// Compute the hash function
int hash(int x)
{
	int tableSize = 100;
	return x % tableSize;
}

void initHashTable(struct HashType* hashTable, int size) {
    hashTable->size = size;
    hashTable->table = (struct ListNode**) malloc(size * sizeof(struct ListNode*));
    for (int i = 0; i < size; ++i) {
        hashTable->table[i] = NULL;
    }
}

void insertRecord(struct HashType* hashTable, struct RecordType record) {
    int index = hash(record.id);
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->data = record;
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
}

void displayHashTable(struct HashType* hashTable) {
    for (int i = 0; i < hashTable->size; ++i) {
        struct ListNode* node = hashTable->table[i];
        printf("Index %d:", i);
        while (node != NULL) {
            printf(" -> [%d, %c, %d]", node->data.id, node->data.name, node->data.order);
            node = node->next;
        }
        printf("\n");
    }
}

// parses input file to an integer array
int parseData(char* inputFileName, struct RecordType** ppData)
{
	FILE* inFile = fopen(inputFileName, "r");
	int dataSz = 0;
	int i, n;
	char c;
	struct RecordType *pRecord;
	*ppData = NULL;

	if (inFile)
	{
		fscanf(inFile, "%d\n", &dataSz);
		*ppData = (struct RecordType*) malloc(sizeof(struct RecordType) * dataSz);
		// Implement parse data block
		if (*ppData == NULL)
		{
			printf("Cannot allocate memory\n");
			exit(-1);
		}
		for (i = 0; i < dataSz; ++i)
		{
			pRecord = *ppData + i;
			fscanf(inFile, "%d ", &n);
			pRecord->id = n;
			fscanf(inFile, "%c ", &c);
			pRecord->name = c;
			fscanf(inFile, "%d ", &n);
			pRecord->order = n;
		}

		fclose(inFile);
	}

	return dataSz;
}

// prints the records
void printRecords(struct RecordType pData[], int dataSz)
{
	int i;
	printf("\nRecords:\n");
	for (i = 0; i < dataSz; ++i)
	{
		printf("\t%d %c %d\n", pData[i].id, pData[i].name, pData[i].order);
	}
	printf("\n\n");
}

// display records in the hash structure
// skip the indices which are free
// the output will be in the format:
// index x -> id, name, order -> id, name, order ....
void displayRecordsInHash(struct HashType *pHashArray, int hashSz)
{
	int i;

	for (i=0;i<hashSz;++i)
	{
		// if index is occupied with any records, print all
	}
}

int main(void)
{
	struct RecordType *pRecords;
	int recordSz = 0;

	recordSz = parseData("input_lab_9.txt", &pRecords);
	printRecords(pRecords, recordSz);
	// Your hash implementation

	struct HashType hashTable;
	
	initHashTable(&hashTable, recordSz * 2);
	for (int i = 0; i < recordSz; ++i)
	{
		insertRecord(&hashTable, pRecords[i]);
	}

	displayHashTable(&hashTable);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

struct Candidate {
    int id;
    char name[50];
    int votes;
};

struct Voter {
    int id;
    char name[50];
    int votedCandidateId;
    int hasVoted;
};

struct Candidate candidates[MAX_CANDIDATES];
struct Voter voters[MAX_VOTERS];

int candidateCount = 0;
int voterCount = 0;

void addCandidate(char name[]) {
    if (candidateCount < MAX_CANDIDATES) {
        candidates[candidateCount].id = candidateCount + 1;
        strcpy(candidates[candidateCount].name, name);
        candidates[candidateCount].votes = 0;
        candidateCount++;
        printf("Candidate added successfully.\n");
    } else {
        printf("Maximum candidates reached.\n");
    }
}

void castVote(int voterId, int candidateId) {
    if (voterId >= 1 && voterId <= voterCount && !voters[voterId - 1].hasVoted) {
        voters[voterId - 1].hasVoted = 1;
        voters[voterId - 1].votedCandidateId = candidateId;
        candidates[candidateId - 1].votes++;
        printf("Vote cast successfully.\n");
    } else {
        printf("Invalid voter ID or voter has already voted.\n");
    }
}

void displayResults() {
    printf("Candidate Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s - Votes: %d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    char candidateName[50];
    char voterName[50];

    do {
        printf("\n1. Add Candidate\n2. Cast Vote\n3. Display Results\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", candidateName);
                addCandidate(candidateName);
                break;
            case 2:
                if (candidateCount == 0) {
                    printf("No candidates available. Please add candidates first.\n");
                } else {
                    printf("Enter your name: ");
                    scanf("%s", voterName);
                    voters[voterCount].id = voterCount + 1;
                    strcpy(voters[voterCount].name, voterName);
                    voters[voterCount].hasVoted = 0;
                    voters[voterCount].votedCandidateId = -1;
                    voterCount++;

                    int candidateId;
                    printf("Available Candidates:\n");
                    for (int i = 0; i < candidateCount; i++) {
                        printf("%d. %s\n", candidates[i].id, candidates[i].name);
                    }
                    printf("Enter candidate ID to vote for: ");
                    scanf("%d", &candidateId);
                    castVote(voterCount, candidateId);
                }
                break;
            case 3:
                if (candidateCount == 0) {
                    printf("No candidates available.\n");
                } else {
                    displayResults();
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 5

struct Candidate
{
    char name[50];
    int votes;
};

struct Candidate candidates[MAX_CANDIDATES];

void initializeCandidates()
{
    strcpy(candidates[0].name, "Candidate 1");
    candidates[0].votes = 0;

    strcpy(candidates[1].name, "Candidate 2");
    candidates[1].votes = 0;

    strcpy(candidates[2].name, "Candidate 3");
    candidates[2].votes = 0;

    strcpy(candidates[3].name, "Candidate 4");
    candidates[3].votes = 0;

    strcpy(candidates[4].name, "Candidate 5");
    candidates[4].votes = 0;
}

void displayCandidates()
{
    printf("List of Candidates:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("\n");
}

void voteForCandidate(int candidateIndex)
{
    if (candidateIndex >= 1 && candidateIndex <= MAX_CANDIDATES)
    {
        candidates[candidateIndex - 1].votes++;
        printf("Vote casted for %s.\n\n", candidates[candidateIndex - 1].name);
    }
    else
    {
        printf("Invalid candidate index.\n\n");
    }
}

void displayResults()
{
    printf("Voting Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}

int main()
{
    initializeCandidates();
    int choice;

    do

    {
        printf("1. Display Candidates\n");
        printf("2. Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayCandidates();
            break;
        case 2:
            displayCandidates();
            printf("Enter the candidate number to vote: ");
            int candidateIndex;
            scanf("%d", &candidateIndex);
            voteForCandidate(candidateIndex);
            break;
        case 3:
            displayResults();
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

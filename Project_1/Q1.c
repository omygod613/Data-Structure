/* CS261- Assignment 1 - Q.1*/
/* Name:I-Shen Liao
 * Date:Oct. 2, 2016
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
    int id;
    int score;
};

struct student* allocate() {
    
    struct student* stud = (struct student*) malloc(10* sizeof(struct student));/* Allocate memory for ten students */
    
    return stud;    /* return the pointer */
}


void generate(struct student* students) {
    
    int i;
    for(i=0; i<10; i++){
        students[i].id=i;
        students[i].score=(i*10)%50;
    }
    /*
     * Generate random ID and scores for 10 students, ID being between
     * 0 and 9, scores equal to (id * 10) % 50.
     */
}


void output(struct student* students) {
    
    int i;
    
    for(i=0; i<10; i++){
        printf("ID%d is %d, Score%d is %d\n", i, students[i].id, i, students[i].score);
    }
    
    /*
     * Output information about the ten students in the format:
     *
     *   ID0 Score0
     *   ID1 score1
     *   ID2 score2
     *   ...
     *   ID9 score9
     */
}

int min(struct student* students) {
    
    int i;
    int tem=0;
    for(i=0; i<10; i++){
        if(students[i].score<tem){
            tem= students[i].score;
        }
    }
    return tem;
    /* return the minimum score */
}

float avg(struct student* students) {
    
    int i;
    float total=0;
    float avgs;
    
    for(i=0; i<10; i++){
        total= total +students[i].score;
    }
    
    avgs= total/10;
    
    return avgs;
    
    /* return the average score */
}

void sort(struct student* students){
    int i, j, Temp,sp;
    for (i=9; i>=0; i--){
        sp=1;
        for (j =0; j <=i; j++)
            if (students[j].score < students[j+1].score){
                Temp = students[j].score;
                students[j].score = students[j+1].score;
                students[j+1].score = Temp;
                sp=0;
            }
        if (sp==1) break;
    }
}

void deallocate(struct student* stud) {
    
    if(stud != NULL){
    free(stud);
    }
    /* Deallocate memory from stud */
}




int main(){
    struct student* stud = allocate();
    generate(stud);
    output(stud);
    sort(stud);
    for (int i=0; i<10; i++) {
        printf("%d %d\n", stud[i].id, stud[i].score);
    }
    printf("Avg: %f \n", avg(stud));
    
    printf("Min: %d \n", min(stud));
    deallocate(stud);
    return 0;
}

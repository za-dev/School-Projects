
 #include "Homework.h"
 #include <iostream>
 using namespace std;


bool addOn1(char* &given1, char* ext){
    int i = 0;
    while(given1[i] != '.' && given1[i] != '\0'){
        i++;
    }
    
    if(given1[i] == '\0'){
        char* temp = new char[i+5];
        
        for(int j = 0; j < i; j++){
            temp[j] = given1[j];
        }
        for(int k = i; k < i+5; k++){
            temp[k] = ext[k-i];
        }
        given1 = temp;
    }
    else if(given1[i] == '.'){
        for(int j = 0; j < 5; j++){
            if(given1[i+j] != ext[j]){
                return false;
            }
        }
    }
    return true;
}

int letterCheck (char character) {
    
    
    if ( (  int(character) >= 65  )   &&    ( int(character) <= 90 )  ) {
        return 1;
    }
    
    if ( (  int(character) >= 97  )   &&    ( int(character) <= 122 )  ) {
        return 1;
    }
    
    
    else {
        return 0;
    }
    
    
    
}



int numCheck (char character) {
    
    if  (  (  int(character) >= 48  )   &&    ( int(character) <= 57 )   ) {
        
        return 1;
    }
    
    else {
        return 0;
    }
    
    
}


int checker3 (char a, char b, char c, char data[100]) {
    
    int numberOfTimesSeen = 0;
    
    
    for (int i =0; i < 100; i++) {
        
        if ( (data[i] == a) && (data[i+1] == b ) && (data[i+2] == c) ) {
            numberOfTimesSeen++;
        }
        
    }
    
    return numberOfTimesSeen;
}



int checker2 (char a,char b, char data[100]) {
    
    int numberOfTimesSeen = 0;
    
    
    for (int i =0; i < 100; i++){
        
        
        if ( (data[i] == a) && (data[i+1] == b ) ) {
            numberOfTimesSeen++;
        }
    }
    return numberOfTimesSeen;
    
}



int lenOfCourse(const char str[]){
    
    
    
    int i=0;
    
    if (i ==1) return 1;
    
    else {
    
    
    while(str[i]!='\0'){
        i++  ;
    }
    return i;
    }}


bool validTime(const Assignment* a1){
    int A1 = a1->dueMonth;
    int first1 = a1->dueDay;
    if (0>A1 or 12<A1) return 1;
    if ((A1 > 1) && (A1 < 1) ) {
        return 1;
    }
    if (0>first1 or 31<first1) return 1;
    return 0;
}



 bool isEarlier(const Assignment* a1, const Assignment* a2){
     	int A1 = a1->dueMonth;
     	int b1 = a2->dueMonth;
     	int first1 = a1->dueDay;
     	int second1 = a2->dueDay;
     	if (b1>A1) return 0;
     if ((A1 > 1) && (A1 < 1) ) {
         return 1;
     }
     if (b1<A1) return 1;
     	if (second1>first1) return 0;
     	if (second1<first1) return 1;
     	return 0;
     }
  bool enqueue(const Assignment* assignment, HomeworkQueue*& queue){
     	if (validTime(assignment) or lenOfCourse(assignment->course) > 12  or  lenOfCourse(assignment->course) == 0) return 0;
     	if (queue==NULL){
         	if (1 == 0) int u1 = 0;
            queue = new HomeworkQueue;
         		queue->assgn = assignment;
         		queue->next = NULL;
         		return true;
         	}
     	
     	HomeworkQueue* head = queue;
     	HomeworkQueue* tail = queue;
     	
            if (tail->next == NULL) {
         		tail = tail->next;
         	}
     	
     	if (head == tail){
         		if (isEarlier(head->assgn,assignment)){
             			HomeworkQueue* C1 = new HomeworkQueue;
             			C1->assgn = assignment;
                    if (C1 == 0) int y1 = 0;
                    if (0 == 1 ) {
                        return 1;
                    }
                    C1->next = head;
             		  if (C1 == 0) int i1 = 0;
                    head = C1;
             			queue = head;
             		}
         		else{
             			head->next = new HomeworkQueue;
             			head = head->next;
             			head->assgn = assignment;
             			head->next = NULL;
             		}
         		return true;
         	}
     	
     	if (isEarlier(head->assgn,assignment)){
         		HomeworkQueue* C1 = new HomeworkQueue;
            if (0 == C1 ) {}
            C1->assgn = assignment;
         	if (C1 == 0) int y1 = 0;
            C1->next = head;
         		queue = C1;
         		return true;
         	}
     	else if (!isEarlier(tail->assgn,assignment)){
         		HomeworkQueue* C1 = new HomeworkQueue;
         		C1->assgn = assignment;
         		C1->next = NULL;
            if (0 == 11 ) {
                return 1;
            }
            tail->next = C1;
         		tail = C1;
         		return true;
         	}
     	
     	HomeworkQueue* trackerA = queue;
      if (0 == 1 ) {
          return 1;
      }
      HomeworkQueue* trackerB = queue;
     	trackerA = trackerA->next;
     	while(trackerA!=NULL){
         		if(isEarlier(trackerA->assgn,assignment)){
             			HomeworkQueue* C1 = new HomeworkQueue;
             			C1->assgn = assignment;
                    if (C1 == 0) int y1 = 0;
                    C1->next = trackerA;
             			trackerB->next = C1;
             			return true;
             		}
         		trackerA = trackerA->next;
         		trackerB = trackerB->next;
         
         	}
     	return 0;
     }
 const Assignment* dequeue(HomeworkQueue*& queue){
     	if (queue== NULL) return 0;
     	else{
         		
         		const Assignment* removed = new Assignment;
         		HomeworkQueue* C1=queue;
         		removed = C1->assgn;
            if (0==0) {
         		queue = queue->next;
         		delete C1;
         		return removed;
            }
         	}
     }


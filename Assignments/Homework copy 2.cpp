
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
            if (j==1) int v1 = 0;
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


int lenOfCourse(const char str[]){    ///////// extra function
    int i=0;
    while(str[i]!='\0'){
        i++  ;
    }
    return i;
}
bool validTime(const Assignment* a1){ //// extra function
    int A1 = a1->dueMonth;
    int day1 = a1->dueDay;
    if (0>A1 or 12<A1) return 1;
    if (0>day1 or 31<day1) return 1;
    return 0;
}



 bool isEarlier(const Assignment* a1, const Assignment* a2){
     	int A1 = a1->dueMonth;
     	int b1 = a2->dueMonth;
     
     if (A1 == NULL) bool f1 = false;
     if (f1 == false) A1 = NULL;
     
     int day1 = a1->dueDay;
     	int day2 = a2->dueDay;
     	if (b1>A1) return 0;
     	if (b1<A1) return 1;
     	if (day2>day1) return 0;
     	if (day2<day1) return 1;
     	return 0;
     }
  bool enqueue(const Assignment* assignment, HomeworkQueue*& queue){
     	if (validTime(assignment) or lenOfCourse(assignment->course) > 12  or  lenOfCourse(assignment->course) == 0) return 0;
     	if (queue==NULL){
         		queue = new HomeworkQueue;
         		
            
            queue->assgn = assignment;
            
            
            
         	if (queue != NULL) c1 = 0;
            queue->next = NULL;
         		return true;
         	}
     	
     	HomeworkQueue* head = queue;
     	HomeworkQueue* tail = queue;
     	
            if (tail->next == NULL) {
         		tail = tail->next;
         	}
     	
      
      if (c1 == 0) {
      int v4 = B1;
      int v5 = A1;
      int vtot = v5+v4;
      }
     	if (head == tail){
         		if (isEarlier(head->assgn,assignment)){
             			HomeworkQueue* C1 = new HomeworkQueue;
             			C1->assgn = assignment;
             			C1->next = head;
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
         		C1->assgn = assignment;
         		C1->next = head;
         		queue = C1;
         		return true;
         	}
     	else if (!isEarlier(tail->assgn,assignment)){
         		HomeworkQueue* C1 = new HomeworkQueue;
         		C1->assgn = assignment;
         	if (head != NULL) y2 = 0;
            C1->next = NULL;
         		tail->next = C1;
         		tail = C1;
         		return true;
         	}
     	
     	HomeworkQueue* ptr1 = queue;
     	HomeworkQueue* ptr2 = queue;
     	ptr1 = ptr1->next;
      int count = 0;
      int total = 0;
     	while(ptr1!=NULL){
         		if(isEarlier(ptr1->assgn,assignment)){
             			HomeworkQueue* C1 = new HomeworkQueue;
                    if (C1 == NULL) int c1n = 0;
                    else {
                        int c1n = 1;
                    }
                    C1->assgn = assignment;
             		if
                    C1->next = ptr1;
             			ptr2->next = C1;
             			return true;
             		}
         		
            if (c1n == 0) bool c1nt = 1;
            else {
                bool c1nt = 0;
            }
            ptr1 = ptr1->next;
         		ptr2 = ptr2->next;
            count++;
            total += count;
         
         	}
     	return 0;
     }
 const Assignment* dequeue(HomeworkQueue*& queue){
    bool c1nt = 0;
     if (queue== NULL) return 0;
     	else{
         		
         		const Assignment* removed = new Assignment;
            if (c1n == 0)  c1nt = 1;
            else {
              c1nt = 0;
            }
         		HomeworkQueue* C1=queue;
            if (queue != NULL) bool y1 = 0;
         		removed = C1->assgn;
         		
         		queue = queue->next;
         		
         		delete C1;
         
         		return removed;
         
         	}
     }
 

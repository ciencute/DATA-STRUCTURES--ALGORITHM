#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *pNext;
};
typedef struct node NODE;
struct list{
    NODE *pHead;// dau danh sach
    NODE *pTail;// cuoi danh sach
};
typedef struct list LIST;
void KhoiTao(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}
NODE *KhoiTaoNODE(int x){
 
    NODE *p = new NODE;// khoi tao cap phat vung nho cho node p
    if (p == NULL) {
        cout<<"khong du bo nho de cap phat";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
void ThemVaoDau(LIST &l, NODE *p){
    if (l.pHead == NULL) {
        l.pHead = l.pTail =p;
    }else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void ThemVaoCuoi(LIST &l, NODE *p){
    if (l.pTail == NULL) {
        l.pHead = l.pTail =p;
    }else{
        l.pTail->pNext =p;
        l.pTail =p;
        
    }
}
int main(int argc, const char * argv[]) {
    
    return 0;
}

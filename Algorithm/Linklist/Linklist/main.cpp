#include <iostream>
using namespace std;
struct node{
    int data;
    struct node *pNext;
};
typedef node NODE;
struct list{
    node *pHead;
    node *pTail;
};

typedef list LIST;
void KhoiTao(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}
NODE *KhoiTaoNode(int x){
    NODE *p = new NODE();
    if (p==NULL) {
        cout<<"khong du bo nho de cap phat";
    }
        p->data = x;
        p->pNext = NULL;
        return  p;
}
void themVaoDau(LIST &l, NODE *p){
    if (l.pHead ==NULL) {
        l.pHead = l.pTail = p;
    }
    p->pNext = l.pHead;
    l.pHead = p;
    
    
}
void thamVaoCuoi(LIST &l, NODE *p){
    if (l.pHead ==  NULL) {
        l.pHead = l.pHead = p;
    }
    l.pTail->pNext = p;
    l.pTail = p;
}
void xuatLinkList(LIST l){
    for (NODE *k = l.pHead; k->pNext!= NULL; k = k->pNext) {
        cout<<"gia tri tung node = "<<k->data<<endl;
    }
}
int main(int argc, const char * argv[]) {
    LIST l;
    KhoiTao(l);
    int n;
    cout<<"nhap so luong node can them"<<endl;
    cin>>n;
    for (int i = 1; i<=n; i++) {
        int x;
        cout<<"Nhap gia tri so nguyen"<<endl;
        cin>>x;
        NODE *p = KhoiTaoNode(x);
        themVaoDau(l, p);
    }
    cout<<"========danh sach lien ket don=============="<<endl;
    xuatLinkList(l);
    return 0;
}

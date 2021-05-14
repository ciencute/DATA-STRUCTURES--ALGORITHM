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
        p->data = x;
        p->pNext = NULL;
        return  p;
}
void themVaoDau(LIST &l, NODE *p){
    if (l.pHead ==NULL) {
        l.pHead = l.pTail = p;
        return;
    }
        p->pNext = l.pHead;
        l.pHead = p;
    // x = 1
    //v1 null == null
    //  p = 1 p head = null
    // phead = 1
    // tail = 1
    // v2
    // x = 2
    // v2 // node ddau tro den phead
    // head = 2
    //head = 3
    // tail == 1
}

void thamVaoCuoi(LIST &l, NODE *p){
    if (l.pHead ==  NULL) {
        l.pHead = l.pHead = p;
        return;
    }
    l.pTail->pNext = p;
    l.pTail = p;
}
void themAffter(LIST &l, NODE *p){
    int x;
    cout<<"nhap gia tri node q"<<endl;
    cin>>x;
    NODE *q = KhoiTaoNode(x);
    if (q->data == l.pHead->data && l.pHead->pNext== NULL) {
        thamVaoCuoi(l, p);
    }else{
        for (NODE *k = l.pHead; k!= NULL; k = k->pNext) {
            if (k->data == q->data) {
                NODE *h = KhoiTaoNode(p->data);
                NODE * g = k->pNext;
                h->pNext = g;
                k->pNext = h;
                k = k->pNext;
            }
        }
    }
}
void xuatLinkList(LIST l){
    for (NODE *k = l.pHead; k!= NULL; k= k->pNext) {
        cout<<"gia tri tung node = "<<k->data<<endl;
    }
   
    
}
void finMax(LIST l){
    int max = 0;
    for (NODE *k = l.pHead; k!= NULL; k= k->pNext) {
        if ((k->data) > max) {
            max = k->data;
        }
    }
    cout<<"so co gia tri lon nhat la "<<max<<endl;
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
    
    int x;
    cout<<"nhap gia tri node p can them vao sau"<<endl;
    cin>>x;
    NODE *p = KhoiTaoNode(x);
    themAffter(l, p);
    
    cout<<"========danh sach lien ket don=============="<<endl;
    xuatLinkList(l);
    finMax(l);
    return 0;
}

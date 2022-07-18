#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//����ڵ�
typedef struct ListNode {
  int data;
  struct ListNode* next;
}ListNode;


//����ṹ
typedef struct Linklist {
  ListNode head;//����ͷ�ڵ�
  int length;
}Linklist;

//��ʼ������ڵ�
ListNode* init_listnode(int val) {
  ListNode* p = (ListNode*)malloc(sizeof(ListNode));
  if (p == NULL)return 0;
  p->data = val;
  p->next = NULL;
  return p;
}

/*ָ��pָ������ͷ�ڵ㣬����ڼ�λ���������߼���*/
//��ʼ������ṹ
Linklist* init_linklist() {
  Linklist* l = (Linklist*)malloc(sizeof(Linklist));
  if (l == NULL)return 0;

  l->head.next = NULL;//����ͷ�ڵ���һλָ��գ�������ͷ�ڵ���һλ���ǵ�0λ
  l->length = 0;
  return l;
}

//���ٲ���
void clear_listnode(ListNode* node) {
  if (node == NULL)return;
  free(node);
  return;
}

void clear_linklist(Linklist* l) {
  if (l == NULL)return;
  ListNode* p = l->head.next, * q;//ָ����������ĵ�һ���ڵ�
  while (p)
  {
    q = p->next;
    clear_listnode(p);
    p = q;
  }
  free(l);
  return;
}


//�������
int insert(Linklist* l, int ind, int val) {
  if (l == NULL)return 0;
  if (ind < 0 || ind > l->length)return 0;
  ListNode* p = &(l->head), *node = init_listnode(val);
  while (ind--)
  {
    p = p->next;
  }
  //��ʱpվ���˴�����ڵ��ǰһ��λ��
  node->next = p->next;
  p->next = node;
  l->length += 1;
  return 1;
}


//ɾ������
int erase(Linklist* l, int ind) {
  if (l == NULL) return 0;
  if (ind < 0 || ind >= l->length) return 0;
  ListNode *p = &(l->head), *q;

  while (ind--)
  {
    p = p->next;
  }
  q = p->next;
  q = q->next;
  clear_listnode(p->next);
  p->next = q;
  l->length -= 1;
  return 1;
}


void output(Linklist* l) {
  printf("LinkList(%d):", l->length);
  for ( ListNode *p = l->head.next; p; p = p->next)
  {
    printf("%d->", p->data);
  }
  printf("NULL\n");
}
#define MAX_OP 30
int main() {
  srand((unsigned)time(0));

  Linklist* l = init_linklist();
  for (int i = 0; i < MAX_OP; i++)
  {
    int op = rand() % 4;
    int ind = rand() % (l->length + 1);
    int val = rand() % 100;
      switch (op)
      {
      case 0:
      case 1: 
      case 2: {
        printf("insert %d at %d to Linklist = %d\n",
          val, ind, insert(l, ind, val));
      }break;
      case 3: {
        printf("erase item at %d to Linklist = %d\n",
           ind, erase(l, ind));
      }break;
      }
      output(l);
      printf("\n");
  }
  return 0;
}
#include <iostream>
using namespace std;
const int STOP = -99;
const int hienThi = 99;
struct node
{
	int data;
	node* link;
};

typedef node* NODEPTR;

struct Queue
{
	NODEPTR front;
	NODEPTR last;
};

void khoiTao(Queue& q)
{
	q.front = q.last = NULL;
}

NODEPTR taoQueue(int x)
{
	NODEPTR p;
	p = new node;
	p->data = x;
	p->link = NULL;
	return p;
}

//Thêm Cuối 
void pushQueue(Queue& q, int x)
{
	NODEPTR p = taoQueue(x);
	if (q.front == NULL)
	{
		q.front = q.last = p;
	}
	else
	{
		q.last->link = p;
		q.last = p;
	}
}

void nhap(Queue& q)
{
	int x;
	do
	{
		cout << "\n Nhap Gia Tri Queue: (-99 De Thoat)"; cin >> x;
		if (x == STOP) break;
		pushQueue(q, x);
	} while (1);
}

void xuat(Queue q)
{
	NODEPTR p = q.front;
	while (p != NULL)
	{
		cout << " " << p->data;
		p = p->link;
	}
}

//Lấy Phần Tử Đầu Tiên Ra Khỏi Queue ( Xóa )
int popQueue(Queue& q)
{
	NODEPTR p = q.front;
	if (q.front != NULL)
	{
		q.front = q.front->link;
		p->link = NULL;
		int gt = p->data;
		delete p;
		return gt;
	}
}

//Lấy Phần Tử Cuối Cùng Ra Khỏi Queue (Xóa Cuối )
int popQueueLast(Queue& q)
{
	NODEPTR p = q.front, before = q.front;
	if (q.front != NULL)
	{
		if (p->link == NULL)
		{
			delete p;
			q.front = NULL;
		}
		else
		{
			while (p->link != NULL)
			{
				before = p;
				p = p->link;
			}
			if (p->link == NULL)
			{
				int gt = p->data;
				delete p;
				before->link = NULL;
				return gt;
			}
		}

	}
}





//Lấy Phần Tử Đầu Tiên Có Giá Trị X Ra Khỏi Queue (Xóa X)
void popQueueX(Queue& q, int x)
{
	while (q.front != NULL)
	{
		int gt = popQueue(q);
		if (gt != x)
		{
			pushQueue(q, gt);
		}
		else
		{
			break;
		}
	}
}

//Hàm Xem Phần Tử Đầu Tiên 
int getFront(Queue& q, int& x)
{
	if (q.front != NULL)
	{
		x = q.front->data;
	}
	return x;
}

// Xuất Vị Trí Các Phần Tử Có Giá Trị X
void xuatViTriPhanTuX(Queue& q, int x)
{
	int vt=0;
	NODEPTR p = q.front;
	if (q.front == NULL)
	{
		q.front = q.last = p;
	}
	else
	{
		while (p != NULL)
		{
			if (p->data == x)
			{
				cout <<"\t "<<vt;
			}
			vt++;
			p = p->link;
		}
	}
}

// Đếm Và Trả Về Số Lượng Phần Tử Có Giá Trị x
int demPhanTuX(Queue& q, int x)
{
	int dem = 0;
	NODEPTR p = q.front;
	if (q.front != NULL)
	{
		while (p != NULL)
		{
			if (p->data == x)
			{
				dem++;
			}
			p = p->link;
		}
	}
	return dem;
}

//Thêm Phần Tử Có Giá Trị X vào Queue

void themPhanTuX(Queue& q, int x)
{
	NODEPTR p = taoQueue(x);
	if (q.front != NULL)
	{
		q.last->link = p;
		q.last = p;
	}
}

// Giả Sử Queue Đang Được Tăng Dần Và Thêm Phần Tử Có Giá Trị X vào Queue đó
void themXVaoQueueTang(Queue& q, int x)
{
	NODEPTR p = taoQueue(x);
	Queue qT;
	khoiTao(qT);
	while (q.front != NULL)
	{
		int pT = popQueue(q);
		if (pT <= x)
		{
			pushQueue(qT, pT);
		}
		else
		{
			pushQueue(qT, x);
			pushQueue(qT, pT);
			break;
		}
	}
	while (q.front != NULL)
	{
		int pT = popQueue(q);
		pushQueue(qT, pT);
	}
	q = qT;
}

//Xóa tất cả các Queue Có Giá Trị Là X
void popAllQueueX(Queue& q, int x)
{
	Queue qT;
	khoiTao(qT);
	while (q.front != NULL)
	{
		while (q.front != NULL)
		{
			int pT = popQueue(q);
			if (pT != x)
			{
				pushQueue(qT, pT);
			}
			else
			{
				break;
			}
		}
	}
	q = qT;
}

//Lấy Phần Tử Cuối Cùng Có Giá Trị X Ra Khỏi Queue
void popQueueXLast(Queue& q, int x)
{
	Queue qT;
	khoiTao(qT);
	while (q.front != NULL)
	{
		while (q.front != NULL)
		{
			int pT = popQueueLast(q);
			if (pT != x)
			{
				pushQueue(qT, pT);
			}
			else
			{
				break;
			}
		}
		if (q.front != NULL)
		{
			int pT = popQueue(qT);
			pushQueue(q, pT);
		}
		q = qT;
	}
}

//Thêm Phần Tử Có Giá Trị Là X Vào Sau Phần Tử Y
void pushQueueXToQueueY(Queue& q, int y, int x)
{
	Queue qT;
	khoiTao(qT);
	NODEPTR p = taoQueue(x);
	while (q.front != NULL)
	{
		int pT = popQueue(q);
		if (pT != y)
		{
			pushQueue(qT, pT);
		}
		else
		{
			pushQueue(qT, pT);
			pushQueue(qT, x);
			break;
		}
	}

	while (q.front != NULL)
	{
		int pT = popQueue(q);
		pushQueue(qT, pT);
	}
	q = qT;
}

// Tách Danh Sách Queue Thành Danh Sách Queue 1 và Queue 2, Trong Đó Danh Sách Queue 1 chứa phần tử lẻ còn Queue 2 chứa phần tử chẵn
void seperateQueue(Queue q, Queue& q1, Queue& q2)
{
	while (q.front != NULL)
	{
		int pT = popQueue(q);
		if (pT % 2 == 0)
		{
			pushQueue(q2, pT);
		}
		else
		{
			pushQueue(q1, pT);
		}
	}
}


int main()
{
	Queue q;
	khoiTao(q);
	Queue q1, q2;
	khoiTao(q1);
	khoiTao(q2);
	int chon = 0;
	do {
		cout << "\n\n\t\t99. Xem Phan Tu Dau Tien Cua Hang Doi: ";
		cout << "\n\n\t\t1. Nhap Danh Sach Hang Doi. ";
		cout << "\n\n\t\t2. Xuat Danh Sach Hang Doi.";
		cout << "\n\n\t\t3. Lay Phan Tu Dau Tien Ra Khoi Hang Doi.";
		cout << "\n\n\t\t4. Lay Phan Tu X Dau Tien Ra Khoi Hang Doi. ";
		cout << "\n\n\t\t5. Xuat Tat Ca Phan Tu Co Gia Tri La X. ";
		cout << "\n\n\t\t6. Dem Va Tra Ve So Luong Phan Tu Co Gia Tri X: ";
		cout << "\n\n\t\t7. Them Phan Tu Co Gia Tri La X Vao Hang Doi.";
		cout << "\n\n\t\t8. Gia Su Queue Dang Duoc Tang Dan Va Them Phan Tu Co Gia Tri X Vao Queue Do. ";
		cout << "\n\n\t\t9. Xoa Tat Ca Phan Tu Co Gia Tri X. ";
		cout << "\n\n\t\t******************** NEW *************************** ";
		cout << "\n\n\t\t10. Them Phan Tu Co Gia Tri La X Vao Trong Queue Co Phan Tu Gia Tri La Y.";
		cout << "\n\n\t\t11. Tach Danh Sach Queue Thanh 2 Danh Sach Queue Chan Va Le.";
		cout << "\n\n\t\t0. Dung!!!!";
		cout << "\n\t\t\t Chon 1 So Nguyen De Thuc Thi:  "; cin >> chon;
		switch (chon)
		{
		case hienThi: 
			int a, xemPhanTu;
			xemPhanTu = getFront(q, a);
			cout << "\n Xem Phan Tu Dau Cua Hang Doi: " << xemPhanTu;
			break;
		case 1:
			system("cls");
			nhap(q);
			break;
		case 2:
			system("cls");
			cout << "\n Danh Sach Hang Doi: ";
			xuat(q);
			break;
		case 3:
			system("cls");
			cout << "\n Lay Phan Tu Dau Tien Ra Khoi Queue ";
			popQueue(q);
			xuat(q);
			break;
		case 4:
			system("cls");
			int x;
			cout << "\n Nhap Gia Tri X: "; cin >> x;
			popQueueX(q, x);
			xuat(q);
			break;
		case 5:
			system("cls");
			cout << "\n Nhap Gia Tri X: "; cin >> x;
			cout << "\n Vi Tri Cua Cac Phan Tu X: ";
			xuatViTriPhanTuX(q, x);
			break;
		case 6:
			system("cls");
			cout << "\n Nhap Gia Tri X: "; cin >> x;
			cout << "\n Tong So Luong Phan Tu X Co Trong Queue La: " << demPhanTuX(q, x);
			break;
		case 7:
			system("cls");
			cout << "\n Nhap Gia Tri X: "; cin >> x;
			themPhanTuX(q, x);
			xuat(q);
			break;
		case 8:
			system("cls");
			cout << "\n Nhap Gia Tri X: "; cin >> x;
			themXVaoQueueTang(q, x);
			xuat(q);
			break;
		case 9:
			system("cls");
			cout << "\n Nhap Gia Tri X: "; cin >> x;
			popAllQueueX(q, x);
			xuat(q);
			break;
		case 10:
			system("cls");
			int y;
			cout << "\n Nhap Gia Tri X: "; cin >> x;
			cout << "\n Nhap Gia Tri Y De X Them Vao: "; cin >> y;
			cout << "\n Them Phan Tu Co Gia Tri La X Vao Trong Queue Co Phan Tu Gia Tri La Y: ";
			pushQueueXToQueueY(q, y, x);
			xuat(q);
			break;
		case 11:
			system("cls");
			cout << "\n Danh Sach Queue Ban Dau: ";
			xuat(q);
			cout << "\n Danh Sach Queue Sau Khi Tach: ";
			cout << "\n ++ Danh Sach Chan ++ ";
			seperateQueue(q,q1,q2);
			xuat(q2);
			cout << "\n ++ Danh Sach Le ++ ";
			xuat(q1);
			break;
		default: 
			break;
		}
	} while (chon != 0);

	return 0;
}
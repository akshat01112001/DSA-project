#include <bits/stdc++.h>
#define ll long long int
#define ISEMPTY cout<<"EMPTY LIST:";

using namespace std;

struct node
{
    int id;
    char name[20];
    int price;
    int qty;
    struct node *next;
};

struct node2
{
    int id;
    int qty;
    struct node2 *next2;
};

typedef struct node snode;
typedef struct node2 snode2;
snode *newnode, *ptr, *prev,*temp;
snode *first = NULL, *last = NULL;
snode2 *newnode2, *ptr2, *prev2,*temp2;
snode2 *first2 = NULL, *last2 = NULL;

void manageProduct()
{
    int ch;
    char ch2;

    while (1)
    {
        cout<<"========================================================="<<endl;
        cout<<"\t\t WELCOME MANAGER!!"<<endl;
        cout<<"========================================================="<<endl;
        cout<<"1. Add New Product"<<endl;
        cout<<"2. Display All Products"<<endl;
        cout<<"0. Back"<<endl;
        cout<<"========================================================="<<endl;
        cout<<"Please enter your Choice: "<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1: {
                addProduct();
                break;
            }
            case 2:{
                displayAllProduct();
                cout<<"Do you wish to remove an Item from Stock[Y/N]? "<<endl;
                cin>>ch2;
                if (ch2 == 'Y'||ch2 == 'y')
                {
                    removeProduct();
                    getch();
                }
                if (ch2 == 'N'||ch2 == 'n')
                {
                    return main();
                }
                break;
            }
            case 0:{
                return;
            }
            default: cout<<"Valid choice not entered!"<<endl;

        }

    }
}

snode* create_node(int id, char *name, int price, int qty)
{
    newnode=(snode*)malloc(sizeof(snode));
    if(newnode==NULL)
    {
        cout<<"Sorry, no Products Available."<<endl;
        return 0;
    }
    else
    {
        newnode->id=id;
        strcpy(newnode->name,name);
        newnode->price=price;
        newnode->qty=qty;
        newnode->next=NULL;
        return newnode;
    }
}

snode2* create_node2(int id, int qty)
{
    newnode2=(snode2*)malloc(sizeof(snode2));
    if(newnode2==NULL)
    {
        cout<<"Sorry, no Products Available."<<endl;
        return 0;
    }
    else
    {
        newnode2->id=id;
        newnode2->qty=qty;
        newnode2->next2=NULL;
        return newnode2;
    }
}

void addProduct()
{
    system("cls");
    int id, price, qty,pos,cnt=0,i;
    cout<<"========================================================="<<endl;
    cout<<"ADD PRODUCTS!!"<<endl;
    cout<<"========================================================="<<endl;
    char name[20],ch;
    cout<<"Enter the ID of the product: "<<endl;
    cin>>id;
    for (ptr = first;ptr != NULL;ptr = ptr->next)
    {
        if (ptr->id==id)
        {
            cout<<"Product ID already in use."<<endl;
            getch();
            return manageProduct();
        }

    }
    cout<<"Enter the name of the product: "<<endl;
    cin>>name;
    cout<<"Enter the price of the product: "<<endl;
    cin>>price;
    cout<<"Enter the quantity of the product: "<<endl;
    cin>>qty;

    newnode = create_node(id, name, price, qty);
    pos = posProduct(id);
    if (pos == 0) {
        if (first == last && first == NULL) {
            first = last = newnode;
            first->next = NULL;
            last->next = NULL;
        } else {
            temp = first;
            first = newnode;
            first->next = temp;
        }
    } else {
        ptr = first;
        while (ptr != NULL) {
            ptr = ptr->next;
            cnt++;
        }
        if (pos == 1) {
            if (first == last && first == NULL) {
                first = last = newnode;
                first->next = NULL;
                last->next = NULL;
            } else {
                temp = first;
                first = newnode;
                first->next = temp;
            }
        } else if (pos > 1 && pos <= cnt) {
            ptr = first;
            for (i = 1; i < pos; i++) {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = newnode;
            newnode->next = ptr;
        } else {
            cout<<"Product Not Found!!"<<endl;
        }
    }

    cout<<"Product Added Successfully!!"<<endl;
    cout<<"Do you want to add another product[Y/N]? "<<endl;
    cin>>ch;
    if (ch == 'Y' || ch == 'y') {
        system("cls");
        return addProduct();
    }
    if (ch == 'N' || ch == 'n') return;

    getch();
}

void displayAllProduct()
{
    system("cls");
    if (first == NULL)
    {
        ISEMPTY;
        cout<<"No Products Available."<<endl;
        getch();
        return main();
    }
    else
    {
        cout<<"========================================================="<<endl;
        cout<<"Product Details"<<endl;
        cout<<"========================================================="<<endl;
        cout<<"ID\t Name\t Qty.\t Price(Rs.)"<<endl;
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        	cout<<ptr->id<<" "<<ptr->name<<" "<<ptr->qty<<" "<<ptr->price<<endl;
        cout<<"========================================================="<<endl;
    }
    getch();
}

void removeProduct()
{
    int id, cnt = 0, i,pos;

    if (first == NULL)
    {
        ISEMPTY;
        cout<<"No Products to delete"<<endl;
    }
    else
    {
        cout<<"Enter the id of value to be deleted: ";
        cin>>id;
        pos=posProduct(id);
        ptr = first;
        if (pos == 1)
        {
            first = ptr->next;
            cout<<"Element deleted"<<endl;
        }
        else
        {
            while (ptr != NULL)
            {
                ptr = ptr->next;
                cnt = cnt + 1;
            }
            if (pos > 0 && pos <= cnt)
            {
                ptr = first;
                for (i = 1;i < pos;i++)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = ptr->next;
            }
            else
            {
                cout<<"Product Not Found!!"<<endl;
                getch();
                return manageProduct();
            }
            free(ptr);
            cout<<"Element deleted"<<endl;
        }
    }
}

int posProduct(int id)
{
    int pos = 0;

    if (first == NULL)
    {
        return pos;
    }
    else
    {
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            pos = pos + 1;
            if (ptr->id == id)
            {
                return pos;
            }
        }

    }

}

int posCart(int id)
{
    int pos = 0;

    if (first2 == NULL)
    {
        return pos;
    }
    else
    {
        for (ptr2 = first2;ptr2 != NULL;ptr2 = ptr2->next2)
        {
            pos = pos + 1;
            if (ptr2->id == id)
            {
                return pos;
            }
        }

    }
}

void purchaseProduct()
{
    int ch;

    while (1)
    {
        system("cls");
        displayAllProduct();
        cout<<"\t\t\n WELCOME CUSTOMER!!"<<endl;
        cout<<"1. Buy a product"<<endl;
        cout<<"0. Back"<<endl;
        cout<<"Please enter your Choice: "<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1: {
                addToCart();
                break;
            }
            case 0:{
                return main();
            }
            default: cout<<"Valid choice not entered!"<<endl;

        }

    }

}

void addToCart()
{
    int id, qty,pos,cnt=0,i;
    char ch;
    cout<<"Enter the ID of the product you wish to add to cart: "<<endl;
    cin>>id;
    for (ptr = first;ptr != NULL;ptr = ptr->next)
    {
        if (ptr->id == id)
        {
            cout<<"Enter the quantity[1-10]: ";
            cin>>qty;
            if (qty<=10) {
                checkStock(id, qty);
                newnode2 = create_node2(id, qty);
                pos=posCart(id);
                if(pos==0)
                {
                    if (first2 == last2 && first2 == NULL)
                    {
                        first2 = last2 = newnode2;
                        first2->next2 = NULL;
                        last2->next2 = NULL;
                    }
                    else
                    {
                        temp2 = first2;
                        first2 = newnode2;
                        first2->next2 = temp2;
                    }
                }
                else
                {
                    ptr2 = first2;
                    while (ptr2 != NULL)
                    {
                        ptr2 = ptr2->next2;
                        cnt++;
                    }
                    if (pos == 1)
                    {
                        if (first2 == last2 && first2 == NULL)
                        {
                            first2 = last2 = newnode2;
                            first2->next2 = NULL;
                            last2->next2 = NULL;
                        }
                        else
                        {
                            temp2 = first2;
                            first2 = newnode2;
                            first2->next2 = temp2;
                        }
                    }
                    else if (pos>1 && pos<=cnt)
                    {
                        ptr2 = first2;
                        for (i = 1;i < pos;i++)
                        {
                            prev2 = ptr2;
                            ptr2 = ptr2->next2;
                        }
                        prev2->next2 = newnode2;
                        newnode2->next2 = ptr2;
                    }
                    else
                    	cout<<"Product Not Found!!"<<endl;
                }
                cout<<"Product Added Successfully!!"<<endl;
            }
            else
            {
                cout<<"Quantity can't exceed 10."<<endl;
                getch();
                return purchaseProduct();
            }
            cout<<"Do you want to add another product[Y/N]? "<<endl;
            cin>>ch;
            if (ch == 'Y'||ch == 'y')
            {
                system("cls");
                return purchaseProduct();
            }
            if (ch == 'N'||ch == 'n')
                return main();
        }

    }

    cout<<"Product Not Found!!"<<endl;
    getch();
    return purchaseProduct();

}

void checkStock(int id, int qty)
{
    if (first == NULL)
    {
        ISEMPTY;
    }
    else
    {
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            if (ptr->id == id)
            {
                if (ptr->qty<qty)
                {
                    cout<<"Not enough products available."<<endl;
                    getch();
                    return purchaseProduct();
                }
            }
        }

    }
}

void viewCart()
{
    system("cls");
    if (first == NULL)
    {
        ISEMPTY;
        cout<<"No Products Available in Cart."<<endl;
        getch();
        return main();
    }
    else
    {
        cout<<"========================================================="<<endl;
        cout<<"PRODUCTS IN CART"<<endl;
        cout<<"=========================================================\n\n"<<endl;
        cout<<"ID\t Name\t Qty.\t Price(Rs.)"<<endl;
        for (ptr2 = first2;ptr2 != NULL;ptr2 = ptr2->next2)
        {
            cout<<ptr2->id<<endl;
            for (ptr = first;ptr != NULL;ptr = ptr->next)
                if (ptr->id==ptr2->id) cout<<ptr->name<<" "<<ptr2->qty<<" "<<ptr->price;
            cout<<endl;
        }
        cout<<"========================================================="<<endl;
    }
    getch();
}

void generateBill()
{
    int ch;
    system("cls");
    viewCart();
    cout<<"1. Modify your cart."<<endl;
    cout<<"2. Proceed to Checkout."<<endl;
    cout<<"0. Back"<<endl;
    cout<<"Please enter your Choice: "<<endl;
    cin>>ch;
    switch (ch)
    {
        case 1: {
            modifyCart();
            break;
        }
        case 2: {
            checkout();
            break;
        }
        case 0:
        {
            return main();
        }
        default: {
            cout<<"Valid choice not entered!"<<endl;
            getch();
            return generateBill();
        }
    }
}

void modifyCart()
{
    int id,qty,ch;
    system("cls");
    viewCart();
    cout<<"Enter the ID of the Product you wish to Modify: "<<endl;
    cin>>id;
    for (ptr2 = first2;ptr2 != NULL;ptr2 = ptr2->next2) {
        if (ptr2->id == id)
        {
            cout<<"1. Delete Product."<<endl;
            cout<<"2. Modify the quantity."<<endl;
            cout<<"0. Back."<<endl;
            cout<<"Please enter your Choice: ";
            cin>>ch;
            switch (ch) {
                case 1: {
                    deleteCart(id);
                    getch();
                    return generateBill();
                }
                case 2: {
                    cout<<"Enter the new quantity[1-10]: ";
                    cin>>qty;
                    if (qty <= 10) {
                        updateCart(id, qty);
                        getch();
                        return generateBill();
                    } else {
                        cout<<"Quantity can't exceed 10."<<endl;
                        getch();
                        return modifyCart();
                    }
                }
                case 0: {
                    return generateBill();
                }
                default: {
                    cout<<"Valid choice not entered!"<<endl;
                    getch();
                    return generateBill();
                }
            }

        }

    }
    cout<<"Product Not Found!!"<<endl;
    getch();
    return generateBill();

}

void deleteCart(int id)
{
    int pos,cnt=0,i;
    if (first2 == NULL)
    {
        ISEMPTY;
        cout<<"No Products to delete"<<endl;
    }
    else
    {
        pos = posCart(id);
        ptr2 = first2;
        if (pos == 1)
        {
            first2 = ptr2->next2;
            cout<<"Product deleted from Cart."<<endl;
        }
        else
        {
            while (ptr2 != NULL)
            {
                ptr2 = ptr2->next2;
                cnt = cnt + 1;
            }
            if (pos > 0 && pos <= cnt)
            {
                ptr2 = first2;
                for (i = 1; i < pos; i++)
                {
                    prev2 = ptr2;
                    ptr2 = ptr2->next2;
                }
                prev2->next2 = ptr2->next2;
            }
            else
            {
                cout<<"Product Not Found!!"<<endl;
                getch();
                return generateBill();
            }
            free(ptr);
            cout<<"Product deleted"<<endl;
        }
    }
}

void updateCart(int id, int qty)
{
    if (first2 == NULL)
    {
        ISEMPTY;
    }
    else
    {
        for (ptr2 = first2; ptr2 != NULL; ptr2 = ptr2->next2)
        {
            if (ptr2->id == id)
            {
                ptr2->qty = qty;
                return generateBill();

            }
        }
    }
}




void checkout()
{
    int total=0;
    char ch;
    viewCart();
    for (ptr2 = first2;ptr2 != NULL;ptr2 = ptr2->next2)
    {
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            if (ptr->id==ptr2->id)
            {
                total+=(ptr2->qty)*(ptr->price);
            }
        }
        cout<<endl;
    }
    cout<<"===================>> Total Bill Amount [Rs:"<<total<<"]"<<endl;
    cout<<"Are you sure you want to checkout[Y/N]?"<<endl;
    cin>>ch;
    if (ch == 'Y'||ch == 'y')
    {
        updateStock();
        clearCart();
        cout<<"Purchase Successful!!"<<endl;
    }
    if (ch == 'N'||ch == 'n')
    	return generateBill();
    getch();

}

void updateStock()
{
    for (ptr2 = first2;ptr2 != NULL;ptr2 = ptr2->next2)
    {
        for (ptr = first; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->id == ptr2->id)
            {
                ptr->qty=(ptr->qty)-ptr2->qty;
            }
        }
    }
}

void clearCart()
{
    for (ptr2 = first2;ptr2 != NULL;ptr2 = ptr2->next2)
    	deleteCart(ptr2->id);
}

void solve()
{
	int ch;

    while (1){
        cout<<"========================================================="<<endl;
        cout<<"\t\t WELCOME TO SHOPPING CART!!"<<endl;
        cout<<"========================================================="<<endl;
        cout<<"1. Manage Product"<<endl;
        cout<<"2. Purchase Product"<<endl;
        cout<<"3. Generate Bill"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"========================================================="<<endl;
        cout<<"Please enter your Choice: ";
        cin>>ch;

        switch (ch)
        {
            case 1: {
                manageProduct();
                break;
            }
            case 2:{
                purchaseProduct();
                break;
            }
            case 3: {
                generateBill();
                break;
            }
            case 0: exit(0);
            default: cout("Valid choice not entered!");
        }

    }
}

int main()
{
	solve();

	return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
class item{
    public:
    string itemname;
    int qty;
    float price;
};
class order{
    public:
    string customer;
    int nofitem;
    item itm[50];
    float total=0;
    order* next;
};
void billHeader(order *od);
void billFooter(order *od);
void generateBill(order* head);
void printBill(order *od);
void showAll(order* od);
void search(string name,order* head);
void analysis(order *head);
int main(int argc, char *argv[])
{
	int choice;
	order *head=new order;
	
    cout<<"\t\t=======Adv. Restaurant=======\n";
	cout<<"\t\t billing system"<<endl;
while(1){
	cout<<"Chose your choice"<<endl;
	cout<<"1. Generate bill"<<endl;
	cout<<"2. Show all bill"<<endl;
	cout<<"3. Search"<<endl;
	cout<<"4. Analysis"<<endl;
	cout<<"5. Exit"<<endl;
	
	cout<<"your choice:  "<<endl;
	cin>>choice;
	if(choice==5)
	break;
	switch(choice){
	    case 1 :
	        generateBill(head);
	        break;
	    case 2:
	        showAll(head);
	        break;	       

	    break;
	    case 4: 
	    analysis(head);
	    break;
	  case 3:
	    string name;
	    cin>>ws;
	    cin>>name;
	    search(name,head);
	}
	}
	cout<<"you are out of program\n"<<endl;
	return 0;
	
}
void printBill(order* od){
    billHeader(od);
    billFooter(od);
}    
void showAll(order* head){
    if(head==NULL){
        cout<<"You donot have any bill to show"<<endl;
        return;
    }
    
    order* temp=head;
    while(temp!=NULL){
        printBill(temp);
        temp=temp->next;
    }
}
void billHeader(order* od){
    cout<<"\t\t=======ADV.Restaurant======="<<endl;
    cout<<"Name of the customer: \t\t"<<od->customer<<endl;
    cout<<"Number of item(s):\t\t "<<od->nofitem<<endl;
    for(int i=0;i<od->nofitem;i++){
    cout<<"Name of the "<<i+1<<" item:\t\t "<<od->itm[i].itemname<<endl;
    cout<<"Quantity of the item "<<i+1<<"\t\t "<<od->itm[i].qty<<endl;
    cout<<"Prize of unit item "<<i+1<<" \t\t"<<od->itm[i].price<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
}}
void billFooter(order* od){
    cout<<"\t\t=========ADV. Restaurant=========="<<endl;
    cout<<"Total: \t\t\t "<<od->total<<endl;
    float discount=0.1*od->total;
    float cgst=0.9*od->total*0.05;
    float sgst=0.9*od->total*0.05;
    float netTotal=od->total-discount+cgst+sgst;
    cout<<"Discount@10\t\t "<<discount<<endl;
    cout<<"cgst@5\t\t\t "<<cgst<<endl;
    cout<<"sgst@5\t\t\t "<<sgst<<endl;
    cout<<"Net total:\t\t"<<netTotal<<endl;
    cout<<"\t\tThanks for coming"<<endl;
    cout<<"\t\tVisit again"<<endl;
    return;
}

void generateBill(order* head){
    if(head==NULL){
    cout<<"Please enter your name: ";
    cin>>ws;
    getline(cin,head->customer);
    cout<<"Enter number of item: ";
    cin>>head->nofitem;
    for(int i=0;i<head->nofitem;i++){
        cout<<"enter name of item "<<i+1<<" : "; cin>>ws;
        getline(cin,head->itm[i].itemname);
        cout<<"enter the quantity: ";
        cin>>head->itm[i].qty;
        cout<<"enter the price of the item: ";
        cin>>head->itm[i].price;
        head->total+=head->itm[i].qty*head->itm[i].price;
    }
    billFooter(head);
    return;
    }
    
    order* od=new order;
    order* temp=head;
   while(temp->next!=NULL)
       temp=temp->next;
   temp->next= od;
    cout<<"Please enter your name: ";
    cin>>ws;
    getline(cin,od->customer);
    cout<<"Enter number of item: ";
    cin>>od->nofitem;
    for(int i=0;i<od->nofitem;i++){
        cout<<"enter name of item "<<i+1<<" : "; cin>>od->itm[i].itemname;
        cout<<"enter the quantity: ";
        cin>>od->itm[i].qty;
        cout<<"enter the price of the item: ";
        cin>>od->itm[i].price;
         od->total+=od->itm[i].qty*od->itm[i].price;
    }
    billFooter(od);
}
void search(string name,order* head){
   if(head==NULL){
       cout<<"you donot have any orders to search"<<endl;
       return;
   }
   order* temp=head;
   while(temp!=NULL){
    if(temp->customer==name){
        printBill(temp);
        cout<<endl;}
        temp=temp->next;
   }
    
}
void analysis(order* head){
    float totalsale=0;
    float avgsale;
    int numberofcustomer=0;
    if(head==NULL){
        cout<<"No customer "<<endl;
        return;
    }
    order* temp=head;
    while(temp!=NULL){
        totalsale+=temp->total*0.9;
        numberofcustomer++;
        temp=temp->next;
    }
    numberofcustomer--;
    avgsale=totalsale/numberofcustomer;
    cout<<endl;
    cout<<"Total number of customers :  "<<numberofcustomer<<endl;
    cout<<"total sale of today "<<totalsale<<endl;
    cout<<"avg sale per customer "<<avgsale<<endl;
    return;
}

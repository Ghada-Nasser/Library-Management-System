#include <iostream>
#include <string>
using namespace std;
class Book{
public:
    Book* Next;
    Book* Prev;
    string ID;
    string BookName;
    string Price;
    string WriterName;

    Book(string data,string name,string pri,string w_name) {
        ID=data;
        Price=pri;
        BookName=name;
        WriterName=w_name;
        Next=Prev=NULL;
    }
};
class library{
public:
    Book*First;
    Book*Last;

    library(){
        First=Last=NULL;
    }
    Book* Search(string id){
        Book* current = First;

        while(current != NULL){
            if(current->ID == id){
                return current;
            }
            else{
                current = current->Next;
            }
        }

        return NULL;
    }
    void Add(string id,string name,string pri,string w_name){
        Book*newBook=new Book(id,name,pri,w_name);
        if(First==NULL&&Last==NULL){
            First=Last=newBook;
        }
        else{

            newBook->Prev = Last;
            Last->Next = newBook;
            Last = newBook;
        }
    }
    void Display(){
        Book* current = First;
        if(current==NULL){
            cout<<"there is no elements to display\n";
        }
        while(current !=NULL){
            cout<< current->BookName<<" ";
            cout<<"\n";
            current = current->Next;
        }
    }
    void DisplayForDetails(string bookName){
        Book* current = First;
        if(current==NULL){
            cout<<"there is no Book with this name\n";
        }
        while(current !=NULL) {
            if (current->BookName == bookName) {
                cout << current->BookName << " ";
                cout << current->WriterName << " ";
                cout << current->ID << " ";
                cout << current->Price << " ";
                break;
            }
            else{
                current=current->Next;
            }
        }
    }
    void Delete(string id){
        Book* pdelete = Search(id);

        if(pdelete != NULL){
            //deleted node is the head
            if(pdelete == First){
                if(pdelete == Last){
                    First = Last =NULL;
                }else{
                    First = First->Next;
                    First->Prev = NULL;
                }
            }
                // deleted node is tail
            else if( pdelete == Last){
                Last = Last->Prev;
                Last->Next = NULL;
            }
                // deleted node is not head or tail
            else{
                pdelete->Prev->Next = pdelete->Next;
                pdelete->Next->Prev = pdelete->Prev;

            }
        }
    }
    void insertAftar(string previd , string newid,string Name,string newPrice ,string WriterName){
        Book* prevBook = Search(previd);
        if(prevBook == Last || prevBook == NULL){
            Add(newid, Name, newPrice,WriterName);
        }else{
            Book* newBook = new Book(newid, Name, newPrice,WriterName);

            newBook->Prev = prevBook;
            newBook->Next = prevBook->Next;
            prevBook->Next = newBook;
            newBook->Next->Prev = newBook;
        }
    }
    void SearchForAbook(string name) {
        int flag=0;
        Book *current = First;
        while (current != NULL) {
            if (current->BookName == name) {
                cout<<"Found,If you want to know more information about the book enter 2\n";
                flag=1;
                break;
            } else {
                current = current->Next;
            }
        }

        if(flag==0){
            cout<<"There is no book with this name\n";
        }
    }
    bool checkIf(string&num){
        for(int i=0;i<num.size();i++){
            if(isdigit(num[i])==false){
                return false;
            }
        }
        return true;
    }
};
int main() {
    library li;
    int num;
    string id,price,prevBookId,bookName,WriterName;
    while(true){
        cout<<"1-Add\n"<<"2-Display\n"<<"3-delete\n"<<"4-Search\n"
            <<"5-InsertAfter"<<"\n"<<"6-Exit\n"
            <<"Please enter a number for a specific function\n";
        cin>>num;
        if(num==1){
            cout<<"please enter the book id\n";
            cin>>id;
            cout<<"please enter the book name\n";
            cin.ignore();
            getline(cin,bookName);
            cout<<"please enter the book price\n";
            cin>>price;
            while(li.checkIf(price)==false){
                cout<<"Please enter the right choice\n";
                cin>>price;
            }
            cout<<"please enter the book writer name\n";
            cin.ignore();
            getline(cin,WriterName);
            li.Add(id,bookName,price,WriterName);
        }
        else if(num==2){
            li.Display();
            cout<<"Please enter the book name you chose\n";
            cin.ignore();
            getline(cin,bookName);
            li.DisplayForDetails(bookName);
        }
        else if(num==3){
            cout<<"please enter the book id\n";
            cin>>id;
            li.Delete(id);
        }
        else if(num==4){
            cout<<"please enter the book name\n";
            cin.ignore();
            getline(cin,bookName);
            li.SearchForAbook(bookName);
        }
        else if(num==5){
            cout<<"please enter the book you want to insert after id\n";
            cin>>prevBookId;
            cout<<"please enter the book you want to insert id\n";
            cin>>id;
            cout<<"please enter the book you want to insert name\n";
            cin.ignore();
            getline(cin,bookName);
            cout<<"please enter the book you want to insert price\n";
            cin>>price;
            cout<<"please enter the book you want to insert writer name\n";
            cin.ignore();
            getline(cin,WriterName);
            li.insertAftar(prevBookId,id,bookName,price,WriterName);
        }
        else if(num==6){
            cout<<"This is the end of the program";
            break;
        }
        else{
            cout<<"Please enter a valid number from the announced services numbers\n";
        }
    }
    return 0;
}
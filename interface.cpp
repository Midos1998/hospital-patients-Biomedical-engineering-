#include "interface.h"

interface::interface()
{
readfile();
screen();

}


void interface::add(){
    cout << string( 100, '\n' );
    int code,age,no_of_drugs=0;
    string name;
    string drugs[5];
    string line;
    cout<<"enter the patient's code : ";
    cin>>code;
    cout<<"enter the patient's age : ";
    cin>>age;
    cout<<"enter the patient's name : ";
    cin.ignore();
    getline(cin,name);
    cout<<"enter the patient's drugs' or just press enter to skip "<<endl;
    do {
        getline(cin,line);
        drugs[no_of_drugs]=line;
        no_of_drugs++;
      } while (!line.empty());
    x.add(code,age,name,drugs,no_of_drugs);
    screen();


}
void interface::del(){
    int code;
    cout<<"enter the code for the patient u wanna remove"<<endl;
    cin>>code;
    x.remove(code);
    cout << string( 100, '\n' );
    screen();
}
void interface::search(){
    int code;
    cout<<"enter the code for the patient u wanna find"<<endl;
    cin>>code;
    TreeNode* f=x.search(code);
    cout << string( 100, '\n' );
    cout<<f->data<<"\t"<<f->age<<"\t"<<f->name<<"\t";
    for(int i=0;i<f->num_of_drugs;i++){
        cout<<f->drugs[i];
        cout<<"\t";
    }
    cout<<endl;
    system("pause");
    screen();


}
void interface::print(){
   cout << string( 100, '\n' );
   x.print(0);
   cout<<endl;
   system("pause");
   screen();

}
void interface::screen(){
    cout << string( 100, '\n' );
    cout<<"*********************************"<<endl;
    cout<<"welcome to the Hospital *********"<<endl<<endl;
    cout<<"Here is the menu:"<<endl;
    cout<<"select the desired operation by pressing its number and then enter"<<endl<<endl;
    cout<<"1.Adding a new Patient"<<endl;
    cout<<"2.Delete a currently existed Patient"<<endl;
    cout<<"3.Search for a Patient with his/her code"<<endl;
    cout<<"4.Print All the Patients"<<endl;
    cout<<"5.Exit"<<endl<<endl;
    int f;
    cin>>f;
    switch(f){
    case 1:
       add();
        break;
    case 2:
        del();
        break;
    case 3:
        search();
        break;
    case 4:
        print();
        break;
    case 5:
        write();
        system("exit");
        break;
    default:
        break;
}
}

void interface::readfile(){
    int counter;
    int id;
    int age;
    int i;
    int liner=0;
    string name;
    string med[5];
ifstream file;

char* token;
char buffer[150];
file.open("data.csv");
while(file.getline(buffer,150)){
    if(liner==0){
        liner++;
        continue;
    }
    token=strtok(buffer,",");
    counter=0;

while(token!=NULL){
    if(counter==0){
        id=atoi(token);
        cout<<token<<endl;
    }else if(counter==1){
        age=atoi(token);
        cout<<token<<endl;
    }else if(counter==2){
        name=token;
        cout<<token<<endl;
    }else if(counter==3){
        char* medtoken=token;
        cout<<token<<endl;
        char* toks;
        toks=strtok(medtoken,"-");
        i=0;
        while(toks!=NULL){
            med[i]=toks;
            i++;
            toks=strtok(NULL,"-");
        }
    }
    counter++;
    token=strtok(NULL,",");

}
counter=0;
x.add(id,age,name,med,i+1);
}
file.close();
}

void interface::write(){
    x.print(10);

}






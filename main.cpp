#include <iostream>

#include "Data.h"
using namespace std;


int main(){

    int num;
        DATA dt;
        InicialiazarData(dt);
    while(num!=9){

        cout<<"1.Inserir Data"<<endl;//
        cout<<"2.Buscar Data"<<endl;//
        cout<<"3.Deletar Data"<<endl;//
        cout<<"4.Mostrar Calendario"<<endl;//
        cout<<"5.Mostrar Data especifica"<<endl;//
        cout<<"6.Inserir Compromiso"<<endl;//
        cout<<"7.Deletar Compromiso"<<endl;
        cout<<"8.Editar Compromiso"<<endl;
        cout<<"9.sair do programa"<<endl;

        num = LerNumeros("Escolhe a Opcao Desejavel ");
        PausLimp();
        switch(num){
        case 1:
            inserirUmaData(dt);
            break;
        case 2:{
                int d = LerNumeros("Insere o dia desejavel");
                int m = LerNumeros("Insere o mes desejavel");
                int aa = LerNumeros("Insere o ano desejavel");
                NOData *nod = GetData(dt,d,m,aa);
                if(nod == NULL) cout<<" Data nao encontrada"<<endl;
                    cout <<nod->dd<<" / "<<nod->mm<<" / "<<nod->yyyy<<" Encontrado"<<endl;
                    break;
                }
        case 3:{

                    int d = LerNumeros("Insere o dia desejavel");
                    int m = LerNumeros("Insere o mes desejavel");
                    int aa = LerNumeros("Insere o ano desejavel");

                    NOData *nod = GetData(dt,d,m,aa);
                    if(nod == NULL) cout<<" Data nao existente"<<endl;

                    if(DeleteData(dt,nod,d,m,aa)) cout<<"Data Deletada com sucesso "<<endl;
                    break;
                }
        case 4:
            MostrarGeral(dt);
            break;
        case 5:
            MostrarDataEspecifica(dt);
            break;
        case 6:
            {int d = LerNumeros("Insere o dia desejavel");
            int m = LerNumeros("Insere o mes desejavel");
            int aa = LerNumeros("Insere o ano desejavel");
            inserirUmCompromisso(dt,GetData(dt,d,m,aa),d,m,aa);
            break;}
        case 7:{
                int d = LerNumeros("Insere o dia desejavel");
                int m = LerNumeros("Insere o mes desejavel");
                int aa = LerNumeros("Insere o ano desejavel");
                if(deletandoComp(dt,d,m,aa))cout<<d<<" / "<<m<<" / "<<aa<< "Deletado"<<endl;
                break;
             }
        case 8:{
                    int d = LerNumeros("Insere o dia desejavel");
                    int m = LerNumeros("Insere o mes desejavel");
                    int aa = LerNumeros("Insere o ano desejavel");
                    int hC = LerNumeros("Insere a hora de inicio a modificar");
                    int hF  = LerNumeros("Insere o minuto a modificar");
                    if(editandoComp(dt,d,m,aa,hC,hF))cout<<" Compromisso de hr inicio "<<hC<<" : "<<hF<<" Modificado"<<endl;
                    break;
                }
        }
    }




/**DATA {









    DATA d;







    InicialiazarData(d);







    InserirNaData(d, 12, 5, 2022);



    InserirNaData(d, 13, 8, 2022);



    InserirNaData(d, 19, 5, 2022);



    InserirNaData(d, 18, 2, 2022);



    InserirNaData(d, 15, 5, 2022);







    mostrarAData(d);







    cout<<endl<<endl;







    DATA d1;







    InicialiazarData(d1);







    InserirEmOrdem(d1, 12, 5, 2022);



    InserirEmOrdem(d1, 13, 8, 2022);



    InserirEmOrdem(d1, 19, 5, 2022);



    InserirEmOrdem(d1, 18, 2, 2022);



    InserirEmOrdem(d1, 15, 5, 2022);







    mostrarAData(d1);







    cout<<endl<<endl;







    if(GetData(d1,12, 5, 2022) == NULL) cout<<"Nao encrontrado"<<endl;



    else{cout<<"Encontrado"<<endl;}







    cout<<endl<<endl;







    DeleteData(d1, 12, 5, 2022);



    DeleteData(d1, 18, 2, 2022);



    mostrarAData(d1);





    cout<<endl<<endl<<"Comproissos"<<endl<<endl;

}*/

/**Compromisso{





    NOData noD;



    InicialiazarCompromiso(noD);



    InserirNoCompromisso(noD,8,30,9,40,"steff lindo maravilhoso mds do ceu");

    InserirNoCompromisso(noD,5,30,7,40,"steff lindo m");

    InserirNoCompromisso(noD,2,30,4,40,"steff lindo mara");

    InserirNoCompromisso(noD,15,30,16,40,"steff lindo maravilhoso ");

    InserirNoCompromisso(noD,22,30,22,40,"steff lindo maravilhoso mds");



    mostrarOCompromisso(noD);



    cout<<endl<<endl;



    NOData noD1;



    InicialiazarCompromiso(noD1);



    InserirNoCompromissoOrdem(noD1,8,30,9,40,"steff lindo maravilhoso mds do ceu");

    InserirNoCompromissoOrdem(noD1,5,30,7,40,"steff lindo m");

    InserirNoCompromissoOrdem(noD1,15,30,16,40,"steff lindo maravilhoso ");

    InserirNoCompromissoOrdem(noD1,2,30,2,40,"steff lindo mara");

    InserirNoCompromissoOrdem(noD1,22,30,22,40,"steff lindo maravilhoso mds");

    InserirNoCompromissoOrdem(noD1,3,45,5,20,"steff lindo mara");

    InserirNoCompromissoOrdem(noD1,14,3,15,30, ".........");



    mostrarOCompromisso(noD1);



    cout<<endl<<endl;



    if(GetCompromissos(noD1,15,30) == NULL) cout<<"Nao encrontrado"<<endl;



    else{cout<<"Encontrado"<<endl;}

    DeleteCompromissos(noD1,15,30);
    DeleteCompromissos(noD1,2,30);

    cout <<endl<<endl;
    mostrarOCompromisso(noD1);
}*/
    return 0;

}

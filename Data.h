

using namespace std;


/**Struct*/
struct Compromisso{

    Compromisso *eloC;
    int hh_comecoC, mm_comecoC, hh_fimC, mm_fimC;
    string texto;
};

struct NOData{

    int dd,mm,yyyy;
    NOData *eloD;
    Compromisso  *comecoC=NULL,*fimC=NULL;
};

struct DATA{

    NOData *comecoD, *fimD;
};


int LerNumeros(string Roteiro){

    int num;
    cout<<Roteiro<<endl;
    cin>>num;
    if(Roteiro=="Insere o dia desejavel"){
        while(num <= 0 || num > 31){
            cout<<"Digite um dia valido"<<endl;
            cin>>num;
        }return num;
    }else if(Roteiro=="Insere o mes desejavel"){
        while(num <= 0 || num > 12){
            cout<<"Digite um mes valido"<<endl;
            cin>>num;
        }return num;
    }else if(Roteiro=="Insere o ano desejavel"){
        while(num < 2023 || num > 2050){
            cout<<"Digite um ano maior que 2023"<<endl;
            cin>>num;
        }return num;
    }else if(Roteiro=="insere a hora de inicio desejavel" || Roteiro=="insere a hora final desejavel" || Roteiro=="Insere a hora de inicio a modificar"){
        while(num < 0 || num > 24){
            cout<<"Digite uma hora valida formato 24hr"<<endl;
            cin>>num;
        }return num;
    }else if(Roteiro=="Insere o minuto de inicio desejavel" || Roteiro=="insere a hora final desejavel" || Roteiro=="Insere a minuto de inicio a modificar"){
        while(num < 0  || num > 59){
            cout<<"Digite um minuto valido"<<endl;
            cin>>num;
        }return num;
    }
    return num;
}

string LerValor(string Roteiro){
    string l;
    cout<<Roteiro<<endl;
    cin>>l;
    return l;
}

void PausLimp(){system("pause");system("cls");}

bool inserirUmCompromisso(DATA &dt,NOData *nod,int d,int m,int yy);

/**Compromissos*/

int CompararHorasInicio(Compromisso *comP,Compromisso *comP1){

   int t_hh = comP->hh_fimC  - comP1->hh_comecoC;

   int t_mm = comP->mm_fimC -  comP1->mm_comecoC;

    if(t_hh != 0) return t_hh;

   else{return t_mm;}

}

int CompararHoras(Compromisso *comP,Compromisso *comP1){

   int t_hh = comP->hh_comecoC  - comP1->hh_fimC;

   int t_mm = comP->mm_comecoC -  comP1->mm_fimC;

    if(t_hh != 0) return t_hh;

    return t_mm;

}

void InicialiazarCompromiso(NOData &noD){

    noD.comecoC = NULL;

    noD.fimC = NULL;

}

bool InserirNoCompromisso(NOData &noD, int hrC, int minC, int hrF, int minF, string texto){

    Compromisso *comP = new Compromisso;

    if(comP == NULL) return false;

    comP->hh_comecoC = hrC;

    comP->mm_comecoC = minC;

    comP->texto = texto;

    comP->hh_fimC = hrF;

    comP->mm_fimC = minF;

    comP->eloC = NULL;

    if(noD.comecoC == NULL){

        noD.comecoC = comP;

        noD.fimC = comP;

    }

    else{

    noD.fimC->eloC = comP;

    noD.fimC = comP;

    }

    return true;


}

void mostrarOCompromisso(NOData *noD){

    Compromisso *comP;

    comP = noD->comecoC;

    while(comP != NULL){

        cout<<"HORA INICIAL = "<<comP->hh_comecoC<<" : "<<comP->mm_comecoC<<endl;

        cout<<"Compromiso : "<<comP->texto<<endl;

        cout<<"HORA FINAL = "<<comP->hh_fimC<<" : "<<comP->mm_fimC<<endl<<endl;

        comP = comP->eloC;

    }

}

bool InserirNoCompromissoOrdem(NOData *noD, int hh_C, int mn_C, int hh_F, int mn_F, string texto){


    cout<<"inserindo Compromiso"<<endl;
    PausLimp();
    Compromisso *comP = new Compromisso;

    comP->hh_comecoC = hh_C;

    comP->mm_comecoC = mn_C;

    comP->hh_fimC = hh_F;

    comP->mm_fimC = mn_F;

    comP->texto = texto;

    comP->eloC = NULL;

    if(comP == NULL) return false;

    if(noD->comecoC == NULL){

        noD->comecoC = comP;

        noD->fimC = comP;

        return true;

    }

    Compromisso *comP1 = noD->comecoC,*comP2 = noD->fimC;

    if(CompararHorasInicio(comP1,comP) > CompararHorasInicio(comP,comP1)){

        comP->eloC = noD->comecoC;

        noD->comecoC = comP;

        return true;

    }

    if(CompararHorasInicio(comP,comP2) > CompararHorasInicio(comP2,comP)){

        noD->fimC->eloC = comP;

        noD->fimC = comP;

        return true;

    }


    while( CompararHorasInicio(comP,comP1) > CompararHorasInicio(comP1,comP) && CompararHorasInicio(comP,comP1->eloC) > CompararHorasInicio(comP1->eloC,comP)){

        comP1 = comP1->eloC;

      }

      comP->eloC = comP1->eloC;

      comP1->eloC = comP;

      return true;

}

Compromisso *GetCompromissos(NOData *noD, int hhC, int mnC){

    Compromisso *comP = noD->comecoC;

    while(comP != NULL){

        if(comP->hh_comecoC == hhC && comP->mm_comecoC == mnC) return comP;

        comP = comP->eloC;

    }return NULL;

}

bool DeleteCompromissos(NOData *noD, int hhC, int mnC){

    Compromisso *antC = NULL, *proC = noD->comecoC;

    while(proC != NULL ){

        if(proC->hh_comecoC == hhC && proC->mm_comecoC == mnC){

            if(proC == noD->comecoC){
                antC = proC->eloC;
                noD->comecoC = antC;
                proC->eloC = NULL;
                return true;
            }
            antC = noD->comecoC;

            while(antC->eloC != proC){
                 antC = antC->eloC;
            }
            antC->eloC = proC->eloC;
            proC->eloC = NULL;
            return true;
        }
        proC = proC->eloC;
    }

}

bool DeleteCompromissosT(NOData *noD){

    Compromisso *antC = NULL, *proC = noD->comecoC;

    while(proC != NULL ){
        DeleteCompromissos(noD,proC->hh_comecoC,proC->mm_fimC);
        proC = proC->eloC;
    }
    return true;
}


/**Data*/

bool anoBisexto(int ano){

    return ((ano % 4==0) && ((!(ano%100==0)) || (ano % 400==0)));
}

NOData *novaData(NOData *nod,int dia, int mes, int ano){

    int arrayDias[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(anoBisexto(ano)) arrayDias[2] = 29;

    if( mes >= 1 && mes<=12 && ano > 2022 && dia > 0 && dia <= arrayDias[mes]){

        nod->dd = dia;
        nod->yyyy = ano;
        nod->mm = mes;
    }

    return NULL;
}

int compararData(NOData *data, NOData *data1){

    int D_anos = data->yyyy - data1->yyyy; // ano - ano1
    int D_mes = data->mm - data1->mm; // mes - mes1
    int D_dias = data->dd -  data1->dd; // dia - dia1

    if(D_anos !=0) return D_anos; //se a diferen�a dos anos for diferente de zero, retorna o valor da diferen�a
    if(D_mes !=0) return D_mes; //se a diferen�a dos meses for diferente de zero, retorna o valor da diferen�a
    return D_dias;
    // porque a fun��o retorna apenas a diferen�a, pra que esse valor � utilizado ?

}

void InicialiazarData(DATA &d){

    d.comecoD = NULL;
    d.fimD = NULL;

}

bool InserirNaData( DATA &d, int dd, int mm, int yyyy ){

    NOData *noD = new NOData;

    //explicar mais uma vez essa fun��o, acredito que � pra caso os valores inseridos forem inexistentes cancelar a fun��o retornando null para o bool
    if( noD == NULL ) return false;
    //define as datas do n�
    novaData(noD,LerNumeros("Insere o dia desejavel"),LerNumeros("Insere o mes desejavel"),LerNumeros("Insere o ano desejavel"));
    //elo do N� recebe NULL
    noD->eloD = NULL;
    //se a primeira data inserida ainda n�o existe, define essa como a primeira data inserida
    if(d.comecoD == NULL){
        d.comecoD = noD;
        d.fimD = noD;
    }else{
        //caso contr�rio, a data inserida ser� a �ltima data, pedir pro Steff explicar de novo essa l�gica
        d.fimD->eloD = noD;
        d.fimD = noD;
    }
    //data inserida
    return true;
}

bool InserirEmOrdem( DATA &d,NOData *noD,int dd,int mm,int aa){


   cout << "inserindo data "<<endl;
   PausLimp();
    NOData *noD1;

    if( noD == NULL) return false;

    novaData(noD,dd,mm,aa);
    noD->eloD = NULL;


    if ( d.comecoD == NULL ){
        d.comecoD = noD;
        d.fimD = noD;
        cout<<"nulo steff"<<endl;
         inserirUmCompromisso(d,noD,dd,mm,aa);
        return true;
    }

    noD1 = d.comecoD;
    if ( compararData(noD1,noD) > compararData(noD,noD1) ){
        noD->eloD = d.comecoD;
        d.comecoD = noD;
        cout<<"1"<<endl;
        inserirUmCompromisso(d,noD,dd,mm,aa);
        return true;
    }
    if ( compararData(noD1,noD) < compararData(noD1,noD) ){
        noD->eloD = d.fimD;
        d.fimD = noD;
        cout<<"2"<<endl;
        inserirUmCompromisso(d,noD,dd,mm,aa);
        return true;
    }
    while( compararData(noD,noD1) < compararData(noD1,noD)  && compararData(noD,noD1->eloD) > compararData(noD1->eloD,noD) ){
        noD1 = noD1->eloD;
    }
    cout<<"3"<<endl;
    noD->eloD = noD1->eloD;
    noD1->eloD = noD;
    inserirUmCompromisso(d,noD,dd,mm,aa);
    return true;

}

void mostrarAData(DATA &d){
    NOData *noD;
    noD = d.comecoD;
    while(noD!=NULL){
       cout<<" horario :  "<<noD->dd<<" : "<<noD->mm<<" : "<<noD->yyyy<<endl;
        noD = noD->eloD;
    }

}

NOData *GetData(DATA &dt, int dd, int mm, int yyyy ){


    NOData *noD = dt.comecoD;

     while(noD!=NULL){


        if(noD->dd == dd && noD->mm == mm && noD->yyyy == yyyy){


            return noD;


        } noD = noD->eloD;

     }

    return NULL;

}

bool DeleteData(DATA &d, NOData* noD,int dd, int mm, int yyyy ){

    NOData  *anD;


    anD = NULL;
        while(noD != NULL){

            if(GetData(d,noD->dd, noD->mm, noD->yyyy) == GetData(d,dd,mm,yyyy)){

                if(noD == NULL) return false;

                if(noD==d.comecoD){

                    anD = noD->eloD;

                    d.comecoD = anD;

                    DeleteCompromissosT(noD);

                    noD->eloD = NULL;
                    break;
                }

                    anD = d.comecoD;

                    while(anD->eloD != noD){
                        anD = anD->eloD;

                    }

                    anD->eloD = noD->eloD;
                    DeleteCompromissosT(noD);

                    noD->eloD = NULL;

                    break;

            }

             noD = noD->eloD;
        }

    delete noD;
    return true;
}


/**Control*/

bool inserirUmaData (DATA &dt){

    NOData *noD =  new NOData;

    int d = LerNumeros("Insere o dia desejavel");
    int m =  LerNumeros("Insere o mes desejavel");
    int a = LerNumeros("Insere o ano desejavel");

    if(GetData(dt,d,m,a)==NULL){
        InserirEmOrdem(dt,noD,d,m,a);
         PausLimp();
            return true;
    }else{
        int line = LerNumeros("Deseja Tentar Novamente \n 1 - sim \n 0 - Nao");
        if(line != 1){
            return false;
        }else{

            cout <<d<<"/"<<m<<"/"<<a<<" \n Data j� existente"<<endl;
                return inserirUmaData(dt);
        }
    }
}

bool inserirUmCompromisso(DATA &dt,NOData *noD,int d, int m,int yy){


    if(GetData(dt,d,m,yy)==NULL){
        cout<<"Data "<< d<<":"<<m<<":"<<yy<<" Nao encontrada"<<endl;
            PausLimp();
                return false;
    }

    int line = LerNumeros("Deseja adicionar compromisso \n 1 -Sim \n 0 -Nao");
    if(line != 1){
        cout<<"Processo da Data "<< noD->dd<<":"<<noD->mm<<":"<<noD->yyyy<<" finalizada"<<endl;
            PausLimp();
                return false;
    }


    NOData nod ;

    Compromisso *comP = noD->comecoC;



         int hrC = LerNumeros("Insere a hora de inicio desejavel");
         int mnC = LerNumeros("Insere o minuto de inicio desejavel");
         int hrF = LerNumeros("insere a hora final desejavel");
         int mnF = LerNumeros("insere o minuto final desejavel");
         string texto = LerValor("Insere seu o titulo do compromisso do dia");

    while(hrF < hrC){

        cout<<"Informa�     es invalidas porfavor verifique e digite novamente"<<endl;
        int hrC = LerNumeros("Insere a hora de inicio desejavel");
         int mnC = LerNumeros("Insere o minuto de inicio desejavel");
         int hrF = LerNumeros("insere a hora final desejavel");
         int mnF = LerNumeros("insere o minuto final desejavel");
         string texto = LerValor("Insere seu o titulo do compromisso do dia");

    }
    while(comP != NULL){

        if(comP->hh_comecoC < hrC && comP->hh_fimC > hrC || comP->hh_comecoC < hrF && comP->hh_fimC > hrF  ){

            cout<<"Informa��es invalidas porfavor verifique e digite novamente"<<endl;
            int hrC = LerNumeros("Insere a hora de inicio desejavel");
            int mnC = LerNumeros("Insere o minuto de inicio desejavel");
            int hrF = LerNumeros("insere a hora final desejavel");
            int mnF = LerNumeros("insere o minuto final desejavel");
            string texto = LerValor("Insere seu o titulo do compromisso do dia");
        }
        comP = comP->eloC;
    }



    if(GetCompromissos(noD,hrC,mnC)==NULL){
          InserirNoCompromissoOrdem(noD,hrC,mnC,hrF,mnF,texto);
            cout<<"Processo Concluido com sucesso"<<endl;
                     return true;
    }else{
        cout << "Data ja tem esse compromisso marcado"<<endl;
         return false;
    }
}

bool MostrarGeral(DATA &dt){

        NOData *noD = dt.comecoD,nod;
        while(noD != NULL){
            cout << " Data [ "<<noD->dd<<":"<<noD->mm<<":"<<noD->yyyy<<" ]"<<endl;
            cout<<endl;
            mostrarOCompromisso(noD);
            cout<<endl<<"---------------------------------------------------------------"<<endl<<endl;
            noD = noD->eloD;
        }return true;
}

bool MostrarDataEspecifica(DATA &dt){

        int d = LerNumeros("Insere o dia desejavel");
        int m = LerNumeros("Insere o mes desejavel");
        int yy = LerNumeros("Insere o ano desejavel");


        NOData *noD = dt.comecoD,*nod=GetData(dt,d,m,yy);
        //

            while( noD != NULL ){
                if(noD->dd == d && noD->mm == m && noD->yyyy == yy){
                    cout << " Data [ "<<noD->dd<<":"<<noD->mm<<":"<<noD->yyyy<<" ]"<<endl;
                        cout<<endl;
                            mostrarOCompromisso(noD);
                            return true;
                }   noD = noD->eloD;
            }
        if(nod==NULL) cout<<"Data Nao encontrada"<<endl;return false;

}

bool deletandoComp (DATA &dt,int dia, int mes, int ano){

    NOData *nod=GetData(dt,dia,mes,ano);
        nod = GetData(dt,dia,mes,ano);
        Compromisso *comP = GetCompromissos(nod,comP->hh_comecoC,comP->mm_comecoC);
        DeleteCompromissos(nod,comP->hh_comecoC,comP->hh_fimC);
        return true;

    if(nod==NULL) cout << "Data nao encontrada"<<endl; PausLimp(); return false;

}

bool editandoComp (DATA &dt,int dia, int mes, int ano, int hh, int mnt){

    NOData *noD,nod;
        Compromisso *comP ;
        noD = GetData(dt,dia,mes,ano);

            comP = GetCompromissos(noD,hh,mnt);
            hh = LerNumeros("Insere a hora de inicio desejavel");
            mnt = LerNumeros("Insere o minuto de inicio desejavel");
            if(GetCompromissos(noD,hh,mnt)!=NULL) cout<<"Horario ja esta em uso"<<endl; PausLimp(); return false;
            if(GetCompromissos(noD,hh,mnt)==NULL){
                comP->hh_comecoC = hh;
                comP->mm_comecoC = hh;
                comP->texto = LerValor("Modifique o titulo do compromisso");
                comP->hh_fimC = LerNumeros("insere a hora final desejavel");
                comP->mm_fimC = LerNumeros("insere o minuto final desejavel");
                return true;
            }

    if(GetCompromissos(noD,hh,mnt)==NULL)cout<<"Compromisso nao encontrado"<<endl; PausLimp(); return false;
    if(GetData(dt,dia,mes,ano)== NULL) cout << "Data nao encontrada"<<endl; PausLimp(); return false;

}




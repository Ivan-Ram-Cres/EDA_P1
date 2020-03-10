char titulo[TAM][50]={"The Smiths-Meat is Murder","Fallout New Vegas","Bioshock Infinite","Tokio Blues-Murakami","Clash the truth-Beach Fossils"};
float precio[TAM]={130,190,140,150,120};
int disponible[TAM]={10,10,10,10,10};
int cantidad[TAM]={0,0,0,0,0};
int aux[TAM]={1,2,3,4,5};

void  menu()
{
    int opc,r=0;
    void ver();
    while(r==0)
    {
        printf("\tBIENVENIDO\n");
        printf("(1)VER CATALOGO\n(2)VER ELEMNTOS EN EL CARRITO\n(3)ELIMINAR ELEMENTO\n(4)AGREGAR ELEMENTO\n");
        printf("(5)SALIR\n");
        if((scanf("%i",&opc))!=1)
        {
           break;
        }
        else
        {
            switch (opc)
            {
                case 1:
                    ver();
                break;
                case 2:
                    elementos();
                break;
                case 3:
                    elim();
                break;
                case 4:
                    agregar();
                break;
                case 5:
                    r=1;
               	return;
		    break;
                default:
                break;
            }
        }
    }
}
void ver()
{
    int i;
    for(i=0;i<TAM;i++)
    {
        printf("Articulo [%i]\t",i+1);
        puts(titulo[i]);
        printf("Precio: $ %g\t",precio[i]);
        printf("Disponible: %i\n",disponible[i]);
    }
}
int elementos()
{
    int r=0,i;
    float total=0;
    for(i=0;i<TAM;i++)
    {
        if(cantidad[i]!=0)
        {
            printf("Num\tARTICULO\tCANTIDAD\tP.U.\tP.T\n");
            printf("%i\t%s\t%i\t%g\t%g\n",aux[i],titulo[i],cantidad[i],precio[i],precio[i]*cantidad[i]);
            total=total+(precio[i]*cantidad[i]);
        }
       // else{break;}
    }
    printf("TOTAL A PAGAR %g\n",total);
}
int elim()
{
    int r=0,del,i,art;
    while(r==0)
    {
        printf("QUE ELEMENTO QUIERE ELIMINAR\n");
        if (scanf("%i",&art)!=0)
        {
            for(i=0;i<TAM;i++)
            {
                if(aux[i]==art)
                {
                    printf("CUANTOS ARTICULOS?\n");
                    if (scanf("%i",&del)!=0)
                    {
                        if(del<=disponible[i])
                        {
                            disponible[i]+=del;
                            cantidad[i]-=del;
                        }
                    }
                }
            }
        }
        else{break;}
        printf("DESEA ELIMINAR OTRO ARTICULO?\n(0)Si\t(1)No\n");
        if (scanf("%i",&r)!=0)
        {
        }
        else{break;}
    }
}
int agregar()
{
    int r=0,art,i,des;
    while(r==0)
    {
        printf("QUE ARTICULO DESEA AGREGAR\n");
        if(scanf("%i",&art)!=0)
        {
            for(i=0;i<TAM;i++)
            {
                if(aux[i]==(art))
                {
                    printf("CUANTOS ARTICULOS?\n");
                    if (scanf("%i",&des)!=0)
                    {
                        if(des<=disponible[i])
                        {
                            disponible[i]-=des;
                            cantidad[i]+=des;
                        }
                    }
                }
            }
        }
        else{break;}
        printf("DESEA AGREGAR OTRO ARTICULO?\n(0)Si\t(1)No\n");
        if (scanf("%i",&r)!=0)
        {

        }
        else{break;}
    }
}


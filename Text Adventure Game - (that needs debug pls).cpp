#include <iostream>
#include <windows.h>
#include <time.h>


using namespace std;

int Story(int level, string player_name, string gend, string gen);

void loading()
{
    int c=0, l=0;
    for(l=0;l<=100; l++)
    {
        cout <<"\t\t\t < System Rebooting >\n\t\t\t  WAFUTE Ver 2.1 Syn\n\t\t\tRecovery Proccess " << l << "%\n" <<endl; //We Are Fighting Until The End
        for( c=0; c<=l; c++)
        {
            cout << char(219);
        }
        if (l==100)
        {
            char ch[] = "\n\n\t\t\t Rebooting Successful\n\t\t Activating All Synapses Completed\n MICROTECH WAFUTE VER 2.1 SYN\n ACTIVATING STYSTEM SETUP NAV ";
            for(int i = 0; ch[i];  i++)
            {
                cout << ch[i];
                Sleep(50);
            } 
            Sleep(700);
        }
        Sleep(10);
        cout << "\b \b";
        system("CLS");
    }
}

class user
{
    private:
    int berserker=100, invi = 200,inv=200;

    public:
    int power=35, health=100,armor=25;
    string name="", weapon="Fists";

    void upgrade(int damage , string wname)
    {
        power += damage;
        weapon = wname;
        armor = berserker;
    }
    void Nova()
    {
        power=berserker;
        armor = inv;
    }
    int decision(string an, string an2, string an3, string an4)
    {
        char  choice=0;
        cout << "\t 1." << an << "\t\t\t 2." << an2 << "\n\t 3." << an3 << "\t\t\t 4." << an4 << "\n > ";
        cin >> choice;

        switch (choice)
        {
            case '1':
            {
                power += ((10*power)/100);
                armor = armor  + 10;
                choice = 1;
                break;
            }
            case '2':
            {
                power += ((20*power)/100);
                armor = armor  + 10;
                choice = 2;
                break;
            }
            case '3':
            {
                power += ((20*power)/100);
                armor = armor  + 5;
                choice = 3;
                break;
            }
            case '4':
            {
                power += ((30*power)/100);
                armor = armor  + 15;  
                choice = 4;
                break;
            }
            default:
            {
                cout <<"Invalid. This Decision does not exist." <<endl;
                choice = 0;
                break;
            }
        }
        return choice;
    }   
};


int fight (string ename, string pname, int pdamage,int edamage,int php,int ehp,int pshield,int eshield,string pwep,string ewep)
{   
    string a="";
    int ran=0,tmp=0;
    bool b_enemy=0;
    srand(time(0));
    do
    {
        Sleep(500);
        ran = rand() % 10;
        system("CLS");
        cout << " " << pname  << "\t\t\t\t\t\t\t\t\t "<< ename <<"\n Health = " << php << "\t\t\t\t\t\t\t\t Health = " << ehp << "\n Armor = " << pshield << "\t\t\t\t\t\t\t\t Armor = " << eshield << "\n Power = " << pdamage << "\t\t\t\t\t\t\t\t Power = "<< edamage <<"\n Weapon = " << pwep << "\t\t\t\t\t\t\t\t Weapon = "<< ewep <<"\n----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "type 'attack' , 'block'" <<endl;
        cin >> a;
        if (a == "attack")
        {
            if ((ran >=0) && (ran<=4))
            {
                b_enemy=0;
                cout << ename << " attacked!" <<endl;
                if (pshield <= 0)
                {
                    php -= edamage;
                }
                if (pshield > 0)
                {
                   pshield -= edamage;
                   if(pshield < 0)
                   {
                       tmp = pshield;
                       pshield = 0;
                       php += tmp;
                   }
                }
                if (eshield <= 0)
                {
                    ehp -= pdamage;
                }
                if (eshield > 0)
                {
                    eshield -= pdamage;
                    if(eshield < 0)  
                    {
                        tmp = eshield ;
                        eshield = 0;
                        ehp += tmp;
                    }
                }
                if(eshield < 0)
                {
                    tmp = eshield;
                    eshield = 0;
                    ehp += tmp;
                }
            }else if ((ran >4) && (ran<=6))
            {
                b_enemy=1;
                cout << ename << " has blocked!" <<endl;
                if (b_enemy==1)
                {
                    continue;
                }
            }else
            {
                cout << ename << " is Idle!"<< endl;
                if (eshield<= 0)
                {
                    ehp -= pdamage;
                }
                if (eshield > 0)
                {
                    eshield -= pdamage;
                    if(eshield < 0)
                    {
                        tmp = eshield;
                        eshield = 0;
                        ehp += tmp;;
                    }
                }
                if(eshield < 0)
                {
                    tmp = eshield;
                    eshield = 0;
                    ehp += tmp;;
                }
            }

        }else if (a=="block")
        {
            if ((ran >=0) && (ran<=4))
            {
                cout << ename << " attacked!" <<endl;
                continue;
            }else if ((ran >4) && (ran<=6))
            {
                cout << ename << " has blocked!" <<endl;
                continue;
            }else
            {
                cout << ename << " is Idle!"<< endl;
                continue;
            }
        }
    }while((php > 0) && (ehp > 0));
    return php;
}

int Story(int level, string player_name, string gen, string gend)
{ 
    user enemy;
    user player;

    int sel=0,hp=0;
    if (level==0)
    {
        char ch[] ="\n  Year 2891, 300 years after Earth was devastated by a catastrophic war known as 'The Great Fall' You were a cyborg warrior that fought in that battle and also one that survived. \nYour body was severely damaged however your brain was still functioning. A scientist named Dr. Dyson Ido while scavenging for parts in the massive scrapyard of Iron City \nfound you and attached a new cyborg body to your brain. Once you woke Dr. Dyson Ido told you that this is not the world you remember, it is a different world where the powerful preys \non the weak.\n\t\t\t\t Still thats not the way it has to be!\n";
        for(int l=0; ch[l]; l++)
        {
            cout << ch[l];
            Sleep(20);
        }
        cout <<"\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
        system("pause");
    }else if (level == 1)           // Level 1
    {
        string a="Hunters Warriors",b="you are not coming",c="straight up to them",d="we wait for them";
        do
        {
            cout << "Dr. Dyson Ido: "<< player_name << "." << player_name << "!" << " They wil come for you! We have to leave, Now!\n" << player_name << ": No! We can not hide forever, I'll have to face them head-on. I have to go back to Zalem, I have to finish what I started 300 years ago. \nDr. Dyson Ido: Then I'm coming with you, where do we start?" <<endl;
            Sleep(300);
            sel=enemy.decision(a,b,c,d);
            player.power += 10;
            if ( sel == 1)
            {
                enemy.name ="Cyborg";
                cout << player_name <<": We.... are going to need some help, if we plan to destroy Zalem and kill Nova, why don't we go to their headquarters \nDr. Dyson Ido: I don't believe the are going to listen us......"<<endl;
                Sleep(300);
                cout << enemy.name << ": Looking for me? Doctor or should I say hunter warrior? \nDr. Dyson Ido: "<<player_name << " he is not a hunter warrior, it's a trap"<<endl;
                system("pause");
                hp=fight(enemy.name,player_name,player.power,enemy.power,player.health,enemy.health,player.armor,enemy.armor,player.weapon,enemy.weapon);
                
            }else if (sel == 2)
            {
                enemy.name = "Dr. Dyson Ido";
                cout <<player_name<<": What? No you are not coming with me! I can't lose you too! "<<"\nDr. Dyson Ido: " << player_name << " You know I'm also a Hunter Warrior, don't you?"<<endl; 
                system("pause");
                hp=fight(enemy.name,player_name,player.power,enemy.power,player.health,enemy.health,player.armor,enemy.armor,player.weapon,enemy.weapon);
                cout << "\nDr. Dyson Ido: " << player_name << "... I still can't let you go on your own!\n" <<player_name <<": On second thought, I can't protect you if you are not near me!\nDr. Dyson Ido: ...Good point. Then..." <<endl;
            }else if (sel == 3)
            {
                enemy.name ="Grewishka";
                cout <<player_name<<": You know I can't say no to a fight! We are going to face them head-on \nDr. Dyson Ido: Aaaah...Thats the spirit of a warrior I was so afraid of." <<endl;
                Sleep(300);
                cout << enemy.name << ": Come here you little flea, so I can pintch your head off" <<endl;
                system("pause");
                hp=fight(enemy.name,player_name,player.power,enemy.power,player.health,enemy.health,player.armor,enemy.armor,player.weapon,enemy.weapon);
                cout << enemy.name << ": You'll pay little flea, Grewishka does not forget! I'm coming for you, BOTH!"<<endl;
                Sleep(500);
            }else if (sel == 4)
            {
                enemy.name ="Grewishka";
                cout <<player_name<<": Just make a trap. We wait for them to come to us and they are definitely going to fall right into it\nDr. Dyson Ido: Ok. I should probably start making the trap."<<endl; 
                Sleep(300);
                cout << enemy.name << ": Come here you little flea, so I can pintch your head off" <<endl;
                system("pause");
                hp=fight(enemy.name,player_name,player.power,enemy.power,player.health,enemy.health,player.armor,enemy.armor,player.weapon,enemy.weapon);
                cout << enemy.name << ": You'll pay little flea, Grewishka does not forget! I'm coming for you, BOTH!"<<endl;
                Sleep(500);
            }
            cout <<enemy.name <<" "<< player_name<< " "<<player.power<< " "<<enemy.power<< " "<<player.health << " "<<enemy.health << " "<<player.armor << " "<<enemy.armor << " "<<player.weapon << " "<<enemy.weapon;
            system("pause");
        }while(sel == 0);
        if (hp<=0)
        {
            level = -2;
        }
    }else if (level == 2)           //Level 2
    {
       string a="the turret",b="lets not draw attention",c="the motorcycle",d="the spaceship";
        player.power+=15;
        player.armor+=15;
        do
        {
            cout << "\nDr. Dyson Ido: We definitely should leave now, they will sent more of them! We need something to espace!" <<endl;
            Sleep(300);
            sel=enemy.decision(a,b,c,d);
            if ( sel == 1)
            {
                enemy.name ="Cyborg";
                cout <<player_name<<": Could you fix that broken turret over there? We could use that to stay under cover, so that we can go to the spaceship\nDr. Dyson Ido: Got it!"<<endl;
                Sleep(300);
                cout << enemy.name << ": You thought that would be so easy?" <<endl;
            }else if ((sel == 2))
            {
                enemy.name = "Gonzu";
                cout <<player_name<<": Wear this so we can blend with the crowd, so that we can go to the spaceship"<<endl;
                Sleep(300);
                cout << enemy.name << ": That's not gonna work this time!" <<endl;
            }else if (sel==3)
            {
                enemy.name = "Cyborg";
                cout <<player_name<<": We could use Hugo's motorcycle, so that we can go to the spaceship\nDr. Dyson Ido: They see find us. "<<player_name<< "Noo!" <<player_name<<endl;
                Sleep(300);
                cout << enemy.name << ": You thought that would be so easy?" <<endl;
            }else if (sel==4)
            {
                enemy.name ="Gonzu";
                cout <<player_name<<": I have an idea... I found a huge ship near the sea, if we could go there we could....." << endl; 
                Sleep(300);
                cout << enemy.name <<": A spaceship huh? Let's see if you survive first little " <<gen<< "!"<<endl;
            }
        }while(sel==0);
        
        system("pause");
        hp=fight(enemy.name,player_name,player.power,enemy.power,player.health,enemy.health,player.armor,enemy.armor,player.weapon,enemy.weapon);
        if (hp<=0)
        {
            level = -2;
        }
    }else if (level == 3)           //Level 3
    {
       string a="fight Niame",b="fight Barjack",c="change you mind and run",d="fight Grewishka";
        player.power+=15;
        player.armor+=15;
        do
        {
            cout << "\nDr. Dyson Ido: "<< player_name << " Now!\n"<<player_name << ": Easier said than done!"<< enemy.name <<": Not so quick little " << gend << "!\nDr. Dyson Ido:  "<<player_name <<" what do we do?\n"<<player_name<<": We fight!"<<endl;
            Sleep(300);
            sel=enemy.decision(a,b,c,d);
            if( sel == 1)
            {
                enemy.name ="Niame";
                enemy.weapon="Prosthetic Blades";
                cout <<player_name<<": I'll fight the one with the blades!\nDr. Dyson Ido: Maybe it's a bit late to say that I want to stay in the lab!"<<endl; 
                Sleep(300);
                cout << enemy.name <<": You are so beutiful I want to rip you open and see if you are ungly inside, like the others!"<<endl;
                system("pause");
                hp=fight(enemy.name,player_name,player.power,enemy.power,player.health,enemy.health,player.armor,enemy.armor,player.weapon,enemy.weapon);
            }else if(sel == 2)
            {
                enemy.name = "Barjack";
                cout <<player_name<<": I'll fight the one with the scythe";
                enemy.weapon="Scythe";
                Sleep(300);
                cout << enemy.name <<": Oh no, look's like " << gen << " got us"<<endl;
                system("pause");
                hp=fight(enemy.name,player_name,player.power,enemy.power,player.health,enemy.health,player.armor,enemy.armor,player.weapon,enemy.weapon);
            }else if (sel == 3)
            {
                cout << player_name << ": is there a chance you have the anti matter grenades on you?\nDr. Dyson Ido: Who the hell carry grenades with him...?"<<endl;
                Sleep(300);
                cout << "Dr. Dyson Ido: Yes I have them....\n"<<player_name<<": Then throw them at them!"<<endl;
                Beep(30, 1000);
                Sleep(300);
                hp=1;
            }else if (sel==4)
            {
                enemy.name ="Grewishka";
                cout <<player_name<<": I do not stand by, in the presence of evil"<<endl; 
                Sleep(300);
                cout << enemy.name <<": I'm not done with you you little flea"<<endl;
                system("pause");
                hp=fight(enemy.name,player_name,player.power,enemy.power,player.health,enemy.health,player.armor,enemy.armor,player.weapon,enemy.weapon);
            }
        }while(sel==0);
        if (hp<=0)
        {
            level = -2;
        }
    }else if (level == 4)           //Level 4
    {
       string a="Danko",b="Rocket Hammer",c="Sword of Long Light",d="Damascus Blade";
        player.power+=15;
        player.armor+=15;
        do
        {
            cout << player_name << ": Next station... Zalem City. Nova I know that you can see me, I'm coming for you! \nDr. Dyson Ido: "<<player_name << " if you are really planing to kill Nova you should need a warrior's weapon! Choose one of these."<<endl;
            Sleep(300);
            sel=enemy.decision(a,b,c,d);
            if( sel == 1)
            {
                player.power = 50;
                player.weapon ="Danko";
                cout <<player_name<<": I'll take the "<<player.weapon << "\nDr. Dyson Ido: Also I think it's time to put your new body."<<endl; 
                Sleep(300);
                cout << " Power = " <<player.power <<" Weapon= " <<player.weapon <<endl;
            }else if (sel == 2)
            {
                player.power = 40;
                player.weapon = "Rocket Hammer";
                cout <<player_name<<": I'll take the "<<player.weapon << "\nDr. Dyson Ido: Also I think it's time to put your new body."<<endl; 
                Sleep(300);
            }else if (sel==3)
            {
                player.power = 60;
                player.weapon = "Sword of Long Light";
                cout <<player_name<<": I'll take the "<<player.weapon << "\nDr. Dyson Ido: Also I think it's time to put your new body."<<endl;  
                Sleep(300);
            }else if (sel==4)
            {
                player.power = 70;
                player.weapon ="Damascus Blade";
                cout <<player_name<<": I'll take the "<<player.weapon << "\nDr. Dyson Ido: Also I think it's time to put your new body."<<endl; 
                Sleep(300);
            }
            player.upgrade(player.power,player.weapon);
        }while(sel==0);
        
    }else if (level == 5)           //Level 5
    {
       string a="I'll kill him and then you",b="Bring your best",c="Nobody gonna stand between me and you",d="You always sent others to do your job";
        player.power+=15;
        player.armor+=15;
        do
        {
            cout <<player_name<<": How do I look? \nDr. Dyson Ido: You look great."<<endl;
            Sleep(2000);
            cout << "\nDr. Dyson Ido: "<< player_name <<". \nNova: I heard you were looking for me.\n" <<player_name <<": Nova! You coward! You are hiding behind puppets\nNova: You want me? You have to get through my champion first!"<<endl;
            Sleep(300);
            sel=enemy.decision(a,b,c,d);
            if( sel == 1)
            {
                enemy.name ="Makaku";
                cout <<"\nNova: Then meet my champion " << enemy.name <<"!\n" <<player_name<<": I'm not impressed" <<endl; 
                Sleep(300);

            }else if ((sel == 2) || (sel ==3))
            {
                enemy.name = "Panzer Kunst";
                cout <<"\nNova: Meet " << enemy.name <<"! You thought you were the only one who survived the 'Fall'? You know he is one who created the the fighting style that you are using even now! " <<player_name<<": Somehow I don't doubt that!"<<endl; 
                Sleep(300);
            }else if(sel==4)
            {
                enemy.name ="Zapan";
                cout <<player_name<<": Zapan is your champion? You are joking, aren't you?"<<endl;
                Sleep(300);
            }
            system("pause");
            hp=fight(enemy.name,player_name,player.power,enemy.power,player.health,enemy.health,player.armor,enemy.armor,player.weapon,enemy.weapon);
        }while(sel==0);
        
        if (hp<=0)
        {
            level = -2;
        }
    }else if (level == 6)           //Level 6
    {
       string a="Go for a solo instant kill cause you are mad!",b="throw him the anti matter grenade",c="attack with Dr Ido",d="do the triple backflip and Panzer Kunst's martial arts!";
       enemy.weapon = "Desty machine pistol";
        do
        {
            cout <<player_name<<": As I said nobody is going to protect you this time!\nNova: I'm not the one who need protection!"<< gend <<endl;
            Sleep(300);
            sel=enemy.decision(a,b,c,d);
            if ( sel == 1)
            {
                enemy.name ="Nova";
                cout <<player_name<<": This fight is between you and me!"<<endl; 
                Sleep(300);

            }else if ((sel == 2) || (sel ==3))
            {
                enemy.name = "Nova";
                cout <<player_name<<": Are there any granades left?\nDr Dyson Ido: Only one! "<< player_name <<": Then we better make good use of it!\nNova: It's so sad for a moment you thought that was going to work." <<endl; 
                Sleep(300);
            }else if (sel==4)
            {
                enemy.name ="Nova";
                cout <<player_name<<": Haaaaaaaiaaaaa!";
                Sleep(300);
            }
            enemy.Nova();
            system("pause");
            hp=fight(enemy.name,player_name,player.power,enemy.power,player.health,enemy.health,player.armor,enemy.armor,player.weapon,enemy.weapon);
            if (hp<=0)
            {
                level = -2;
            }
        }while(sel==0); 
    }else
    {
        cout <<"end";
    }
    
    return level;
}

int main()
{
    int x=0,n=0;
    string answ="",player_name,gend,gen;
    do
    {
        n=6;
        cout << "\t\t\t\t A.B.A. Text Adventure \n\n 1.Start Game \n 2.Credits \n 3. Exit \n > ";
        cin >> x;
        if (x==2)
        {
            cout << " A.B.A. Text Adventure \n Based on: Alita Battle Angel \n Software used: Visual Studio \n Code in C++ \n Date: Thursday March 31 \n Year: 2022"<<endl;
            system("pause");
            system("CLS");
        }else if (x==1)
        {   
            cout << "Enter your nickname: ";
            cin >> player_name;
            do
            {
                do
                {
                
                    cout << "Do you want to play as a 'male' or a 'female' character?: ";
                    cin >> gend;
                    system("CLS");
                    if ((gend=="male")||(gend=="Male") || (gend=="MALE") || (gend=="1"))
                    {
                        gen="he";
                        gend="boy";
                        break;
                    }else if ((gend=="female")||(gend=="Female") || (gend=="FEMALE") || (gend=="2"))
                    {
                        gen="she";
                        gend="girl";
                        break;
                    }
                }while((gend!= "male") || (gend!="Male") || (gend!="MALE") || (gend!="female") || (gend!="Female") || (gend!="FEMALE") || (gend!="1") || (gend!="2"));
                do
                {
                    if ((n>=0) && (n<=6))
                    {
                        n=Story(n,player_name,gend,gen);          //Levels
                        if (n==0)
                        {
                            loading();
                        }
                    }
                    n++;
                    if(n==-1)
                    {
                        answ="";
                        do
                        {
                            cout <<"\n Do You want to start again? (y/n)\n >";
                            cin >> answ;
                            if (answ == "y")
                            {
                                cout << "Select Level from '0-6'\n >";      //select level
                                cin >> n;
                            }else if (answ=="n")
                            {
                                x=0;
                                //n=0;
                                system("CLS");
                                break;
                            } 
                        }while((answ!="y") || (answ!="n"));
                    }
                    break;
                }while((n>=0) || (n<=6));
                gend="";
                break;
            }while((n<0) && (n>6));
        }else if(x==3)
        {
            break;
        }
    }while(x!=1);
    return 0;
}

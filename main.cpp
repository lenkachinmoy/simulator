#include <iostream>
#include<ctime>
#include<string>
#include<random>

using namespace std;

int main()
{
    cout<<"*** Skeletons vs Humans ***\n";
    int human,skeleton;

    //Getting the number of human
    cout<<"Enter the number of humans: ";
    cin>>human;

    int startHumans=human;

    //Getting the number of skeletons
    cout<<"Enter the number of skeletons: ";
    cin>>skeleton;
    int startSkeletons=skeleton;

    cout<<"\nBeginning Combat!\n";

    //Human properties
    float humanAttack=0.6f;
    float humanHealth=250.0f;
    float humanDamage=200.0f;
    float currentHumanHealth=humanHealth;

    //Skeleton Properties
    float skeletonAttack=0.5f;
    float skeletonHealth=150.0f;
    float skeletonDamage=50.0f;
    float currentSkeletonHealth=skeletonHealth;

    default_random_engine randomGenerator(time(NULL));
    uniform_real_distribution<float> attack(0.0f,1.0f);


    float attackResullt;
    char turn='H';

    //attack simulation
    while(human>0 && skeleton>0)
    {
        attackResullt=attack(randomGenerator);
        if(turn=='H')
        {
            if(attackResullt<=humanAttack)
            {
                skeletonHealth-=humanDamage;
                if(skeletonHealth<0)
                {
                    skeleton--;
                    skeletonHealth=currentSkeletonHealth;
                }
            }
            turn='S';
        }
        else
        {
            if(attackResullt<=skeletonAttack)
            {
                humanHealth-=skeletonDamage;
                if(humanHealth<0)
                {
                    human--;
                    humanHealth=currentHumanHealth;
                }
            }
            turn='H';
        }
    }
    //printing the result
    cout<<"\n-------Battle's Over-------\n";
    if(human>0)
    {
        cout<<"Humans WON!!!\n";
        cout<<"There are "<<human<<" humans left\n";
    }
    else
    {
        cout<<"Skeletons WON!!!\n";
        cout<<"There are "<<skeleton<<" skeletons left\n";
    }
    cout<<"Number of humans died:: "<<(startHumans-human)<<endl;
    cout<<"Number of skeletons died:: "<<(startSkeletons-skeleton)<<endl;
    return 0;
}

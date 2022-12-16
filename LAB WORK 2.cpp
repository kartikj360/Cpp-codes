#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SET{
    int set_length;
    vector <int> s;

    public:
    SET(){
        int n;
        cout<<"\n\nENTER THE NUMBER OF ELEMENTS IN THE SET YOU ARE GOING TO ENTER= ";
        cin>>n;

        int a1[n];
        cout<<"\n\nENTER ALL THE ELEMENTS OF THE SET= \n";

        for (int i = 0; i < n; i++)
        {
            cin>>a1[i];
        }

        int l=0;
        for (int i = 0; i < n; i++)
        {
            int v=0;
    
            for (int j = 0; j < l; j++)
            {
                if(s[j]==a1[i]){ v=1; break;}
            }

            if(v==0){ s.push_back(a1[i]); l++;}
        }
        
        set_length=l;
    }

    void get_set(){
        cout<<"\n\nNO OF ELEMENTS STORED IN THE SETS IS= "<<set_length;
        cout<<"\n\nYOUR SET STORED WITH US LOOKS LIKE:- \n";
        for (int i = 0; i < set_length; i++)
        {
            cout<<s[i]<<" ";
        }
        cout<<"\n\n";
    }

    bool check_subset(SET &s2){
    	
    	for(int i=0;i<s2.set_length;i++){
    		int v=0;
    		
    		for(int j=0;j<set_length;j++){
    			if(s[j]==s2.s[i]){ v=1; break;}
			}
			
			if(v==0){ return false;}
		}
    	
    	return true;
	}

	void make_union(SET &s2){
		
		vector <int> v;
		for(int i=0;i<set_length;i++){
			
			int ve=0;
			for(int j=0;j<v.size();j++){
				if(v[j]==s[i]){ ve=1; break;}
			}
			
			if(ve==0){ v.push_back(s[i]);}
		}
		
		for(int i=0;i<s2.set_length;i++){
			
			int ve=0;
			for(int j=0;j<v.size();j++){
				if(v[j]==s2.s[i]){ ve=1; break;}
			}
			
			if(ve==0){ v.push_back(s2.s[i]);}
		}
		
		cout<<"\n\n\t\t\t    !!!! UNION OF SET 1 AND SET 2 IS !!!! \n";
		cout<<"\t\t\t\t\t{ ";
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		
		cout<<"}"<<endl<<"\n";
	}
	
	void make_intersection(SET &s2){
		
		vector <int> v;
		for(int i=0;i<set_length;i++){
			
			int ve=0;
			for(int j=0;j<s2.set_length;j++){
				if(s2.s[j]==s[i]){ ve=1; break;	}
			}
			
			if(ve==1){  v.push_back(s[i]);	}
		}
		
		cout<<"\n\n\t\t\t    !!!! INTERSECTION OF SET 1 AND SET 2 IS !!!! \n";
		cout<<"\t\t\t\t{ ";
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		
		cout<<"}"<<endl<<"\n";
	}

	void cartesian_product(SET &s2){
		cout<<"\n\t!!!!  YOUR REQUIRED CARTESIAN PRODUCT IS:-  !!!!\n\n";
        for (int i = 0; i < set_length; i++)
        {
        
            for (int j = 0; j < s2.set_length; j++)
            {
                cout<<"{ "<<s[i]<<", "<<s2.s[j]<<" }";
            }
            
        }
        cout<<"\n\n";
	}

	void set_difference(SET &s2){
		vector <int> v;
		
		for(int i=0;i<set_length;i++){
			int ve=0;
			for(int j=0;j<s2.set_length;j++){
				if(s2.s[j]==s[i]){	ve=1; break;}
			}
			
			if(ve==0){	v.push_back(s[i]);}
		}
		
		cout<<"\n\t\t!!!! REQUIRED SET DIFFERENCE IS !!!!\n";
        cout<<"\t\t{ ";
                    
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
		}
		cout<<"}\n\n";
	}
	
	void symmetric_difference(SET &s2){
		vector <int> v1;
		for (int i = 0; i < set_length; i++)
		{

			int ve=0;
			for (int j = 0; j < s2.set_length; j++){
				if(s2.s[j]==s[i]){ ve=1; break;}
			}
			if(ve==0){ v1.push_back(s[i]);}
		}

		vector <int> v2;
		for (int i = 0; i < s2.set_length; i++)
		{

			int ve=0;
			for (int j = 0; j < set_length; j++){
				if(s2.s[i]==s[j]){ ve=1; break;}
			}
			if(ve==0){ v2.push_back(s2.s[i]);}
		}

		vector <int> ans;
		for(int i=0;i<v1.size();i++){
			
			int ve=0;
			for(int j=0;j<ans.size();j++){
				if(ans[j]==v1[i]){ ve=1; break;}
			}
			
			if(ve==0){ ans.push_back(v1[i]);}
		}
		
		for(int i=0;i<v2.size();i++){
			
			int ve=0;
			for(int j=0;j<ans.size();j++){
				if(ans[j]==v2[i]){ ve=1; break;}
			}
			
			if(ve==0){ ans.push_back(v2[i]);}
		}

		cout<<"\n\n\t\t\tSYMMETRIC DIFFERENCE OF SET 1 AND SET 2\n";
		cout<<"\t\t\t{ ";

		for (int i = 0; i < ans.size(); i++)
		{
			cout<<ans[i]<<" ";
		}

		cout<<"}\n\n";
	}


};


int main(){

    cout<<"\t\tSELECT FROM THE FOLLOWING OPERATIONS YOU WANT TO PERFORM:- \n";
    cout<<"\t\t\t1. CREATE A NEW SET FROM ENTERED ELEMENTS.\n";
    cout<<"\t\t\t2. CHECK WHETHER A SET IS A SUBSET OF ANOTHER.\n";
    cout<<"\t\t\t3. CALCULATE UNION AND INTERSECTION OF TWO SETS.\n";
    cout<<"\t\t\t4. CALCULATE CARTESIAN PRODUCT OF TWO SETS.\n";
    cout<<"\t\t\t5. CALCULATE SYMMETRIC DIFFERNCE OF TWO SETS.\n";
    cout<<"\t\t\t6. CALCULATE SET DIFFERENCE OF TWO SETS.\n";
    cout<<"\t\t\t7. CALCULATE COMPLEMENT OF A SET.( DONT'T SELECT IT IS UNDER DEVELOPMENT )\n";
    cout<<"\n\n\t\t\tENTER YOUR SELECTION AMONG THE ABOVES:- ";
    int input;
    cin>>input;
    
    switch(input)
	{
    	case 1:
    		{
    			SET s1;
    			s1.get_set();
    			break;
			}
			
		case 2:
			{
				cout<<"\n\n  !!! WE ARE PERFORMING OPERATION TO CHECK WHETHER ENTERED S1 IS A SUBSET OF SET 2 SO ENTER INPUT ACCORDING TO IT !!!!";
				cout<<"\n\n\t\t\t\t\tSET1 MAKING:-\n";
    			SET s1;
    			
    			cout<<"\n\n\t\t\t\t\tSET2 MAKING:-\n";
    			SET s2;
    			
    			if(s2.check_subset(s1)){
    				cout<<"\n\t\t\t\t!!!! SET 1 IS SUBSET OF SET2 !!!!\n\n";
				}
				else{
					cout<<"\n\t\t\t\t!!!! SET 1 IS NOT A SUBSET OF SET2 !!!!\n\n";
				}
				
    			break;
			}
			
		 case 3:
		 	{
		 		cout<<"\n\n\t\t\tWHAT YOU WANT TO DO?:-\n";
		 		cout<<"\t\t\t1. UNION OF THE TWO SETS\n";
		 		cout<<"\t\t\t2. INTERSECTION OF THE TWO SET\n";
		 		cout<<"\t\t\t3. BOTH UNION AND INTERSECTION OF THE TWO SETS\n";
		 		cout<<"\n\n\t\t\tENTER YOUR SELECTION:- ";
		 		int x;
				cin>>x;
				
				switch(x){
					case 1:
						{
							cout<<"\n\n\t\t\t\t\tSET 1 MAKING:- \n";
							SET s1;
							
							cout<<"\n\n\t\t\t\t\tSET2 MAKING:-\n";
    						SET s2;
    						
    						s1.make_union(s2);
    						break;
						}
						
					case 2:
						{
							cout<<"\n\n\t\t\t\t\tSET 1 MAKING:- \n";
							SET s1;
							
							cout<<"\n\n\t\t\t\t\tSET2 MAKING:-\n";
    						SET s2;
    						
    						s1.make_intersection(s2);
    						break;
						}
						
					case 3:
						{
							cout<<"\n\n\t\t\t\t\tSET 1 MAKING:- \n";
							SET s1;
							
							cout<<"\n\n\t\t\t\t\tSET2 MAKING:-\n";
    						SET s2;
    						
    						s1.make_union(s2);
    						s1.make_intersection(s2);
    						break;
						}
					default:
                	cout<<"\n\n\t\t\t\t!!!!! WRONG INPUT ENTERED !!!!!\n\n\n";
                	break;	
				}
				break;
			}
		
        case 4:
            {
                cout<<"\n\n\t!!!! WE ARE GOING TO CALCULATE CARTESIAN PRODUCT OF ENTERED TWO SETS !!!!\n\n";

                cout<<"\n\n\t\t\t\t\tSET1 MAKING:-\n";
    			SET s1;
    			
    			cout<<"\n\n\t\t\t\t\tSET2 MAKING:-\n";
    			SET s2;
    			
                cout<<"\t\t\tCHOOSE ONE AMONG THE FOLLOWINGS:- \n";
                cout<<"\t\t\t1. SET1 x SET2\n";
                cout<<"\t\t\t2. SET2 x SET1\n\n";
                cout<<"\t\t\tENTER YOUR SELECTION:- ";
                int x; cin>>x;

                switch (x)
                {
                case 1:
                    s1.cartesian_product(s2);
                    break;
                
                case 2:
                    s2.cartesian_product(s1);
                    break;
                default:
                	cout<<"\n\n\t\t\t\t!!!!! WRONG INPUT ENTERED !!!!!\n\n\n";
                	break;
                }
                break;
            }
    
		case 5:
			{
				cout<<"\n\t\t!!!! WE ARE GOING TO CALCULATE SYMMETRIC DIFFERNCE OF TWO SETS !!!!\n";
				
				cout<<"\n\n\t\t\t\t\tSET1 MAKING:-\n";
    			SET s1;
    			
    			cout<<"\n\n\t\t\t\t\tSET2 MAKING:-\n";
    			SET s2;
    			
    			s1.symmetric_difference(s2);
				break;
			}
			
		case 6:
			{
				cout<<"\n\t\t!!!! WE ARE GOING TO CALCULATE SET DIFFERNCE OF TWO SETS !!!!\n";
				
				cout<<"\n\n\t\t\t\t\tSET1 MAKING:-\n";
    			SET s1;
    			
    			cout<<"\n\n\t\t\t\t\tSET2 MAKING:-\n";
    			SET s2;
    			
    			cout<<"\t\t\tCHOOSE ONE AMONG THE FOLLOWINGS:- \n";
                cout<<"\t\t\t1. SET1 - SET2\n";
                cout<<"\t\t\t2. SET2 - SET1\n\n";
                cout<<"\t\t\tENTER YOUR SELECTION:- ";
                int x; cin>>x;

                switch (x)
                {
                case 1:
                    s1.set_difference(s2);                   
                    break;
                
                
                case 2:
                   s2.set_difference(s1);
                    break;
                    
                default:
                	cout<<"\n\n\t\t\t\t!!!!! WRONG INPUT ENTERED !!!!!\n\n\n";
                	break;
                }
                
				break;
			}	
		
		default:
        
		    cout<<"\n\n\t\t\t\t!!!!! WRONG INPUT ENTERED !!!!!\n\n\n";
            break;
	}
	
	
    return 0;
}

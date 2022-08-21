#include <bits/stdc++.h>
using namespace std;

struct Types_of_Pizza{
 int Small_Qty,Med_Qty,Lg_Qty,others,Fresh_Crispt_Pan,Cheese_Bursting,Thin_wheat_crusting;
};
struct Cost_of_Pizza{
 int SM_Cost,MED_Cost,LG_Cost,Fresh_Crisp_Pan_Cost,Cheese_Bursting_Cost,Thin_wheat_crusting_cost;
};

class Restro{
	char Menu[12][100];
	struct Types_of_Pizza pizzaCart[100];
	struct Cost_of_Pizza costOnSize[12];
	int sidesCost[4];
	public:
		vector<int> cart_ids;
		Restro(char Menu[12][100], int cost[24], int sidesCost[4]){
			int i=0,j=0;
			for(i=0;i<12;i++){
				strcpy(this->Menu[i],Menu[i]);
			}
			i=0;
			for(i=0;i<12;i++)
			{
			  this->pizzaCart[i].Small_Qty=0;
			  this->pizzaCart[i].Med_Qty=0;
			  this->pizzaCart[i].Lg_Qty=0;
			  this->pizzaCart[i].Fresh_Crispt_Pan=0;
			  this->pizzaCart[i].Thin_wheat_crusting=0;
			  this->pizzaCart[i].Cheese_Bursting=0;
			  this->pizzaCart[i].others=0;
			}
			i=0;
			while(i<24)
			{
				this->costOnSize[j].SM_Cost=cost[i++];
				this->costOnSize[j].MED_Cost=cost[i++];
				this->costOnSize[j].LG_Cost=cost[i++];
				this->costOnSize[j].Fresh_Crisp_Pan_Cost=30;
				this->costOnSize[j].Cheese_Bursting_Cost=95;
				this->costOnSize[j].Thin_wheat_crusting_cost=40;
				j++;
			}
			i = 0;
			for(i=0;i<4;i++){
				this->sidesCost[i] = sidesCost[i];
			}
		}
		
		void printMenu(){
			int choice = 0;
			//do{
				printf("Enter \n");
				printf("1 - Veg Pizzas \n");
				printf("2 - Non-Veg Pizzas \n");
				printf("3 - Sides \n");
				printf("4 - Exit \n");
				scanf("%d",&choice);
				switch(choice){
					case 1:{
						int pizza_choice, size, crust;
						printf("\n Enter \n");
						printf("1 - %s \n",this->Menu[0]);
						printf("2 - %s \n",this->Menu[1]);
						printf("3 - %s \n",this->Menu[2]);
						printf("4 - %s \n",this->Menu[3]);
						scanf("%d", &pizza_choice);
						printf("You chose %s \n", this->Menu[pizza_choice-1]);
						printf("\n Enter Size\n");
						printf("1 - Small \n");
						printf("2 - Medium \n");
						printf("3 - Large \n");
						scanf("%d", &size);
						printf("\n Enter Crust\n");
						printf("1 - Fresh Crispy Pan \n");
						printf("2 - Cheese Burst \n");
						printf("3 - Thin Wheat Crust \n");
						scanf("%d", &crust);
						this->addToCart(pizza_choice-1,size,crust);
						break;
					}
					case 2:{
						int pizza_choice,size, crust;
						printf("\n Enter \n");
						printf("1 - %s \n",this->Menu[4]);
						printf("2 - %s \n",this->Menu[5]);
						printf("3 - %s \n",this->Menu[6]);
						printf("4 - %s \n",this->Menu[7]);
						scanf("%d", &pizza_choice);
						printf("You chose %s \n", this->Menu[pizza_choice+4-1]);
						printf("\n Enter Size\n");
						printf("1 - Small \n");
						printf("2 - Medium \n");
						printf("3 - Large \n");
						scanf("%d", &size);
						printf("\n Enter Crust\n");
						printf("1 - Fresh Crispy Pan \n");
						printf("2 - Cheese Burst \n");
						printf("3 - Thin Wheat Crust \n");
						scanf("%d", &crust);
						this->addToCart(pizza_choice+4-1,size,crust);
						break;
					}
					case 3:{
						int pizza_choice;
						printf("\n Enter \n");
						printf("1 - %s \n",this->Menu[8]);
						printf("2 - %s \n",this->Menu[9]);
						printf("3 - %s \n",this->Menu[10]);
						printf("4 - %s \n",this->Menu[11]);
						scanf("%d", &pizza_choice);
						printf("You chose %s \n", this->Menu[pizza_choice+8-1]);
						this->addToCart(pizza_choice+8-1,0,0);
						break;
					}
					case 4:{
						break;
					}
				}
				
			//}while(choice > 0 && choice < 5);
		}
		
		void viewCart()
		{
		int totalCost=0,i;
		printf("---------------------List in Cart-------------------------\n");
		for(i=0;i<12;i++)
		{
			if(
				this->pizzaCart[i].Small_Qty>0||
				this->pizzaCart[i].Med_Qty>0||
				this->pizzaCart[i].Lg_Qty>0||
				this->pizzaCart[i].others>0||
				this->pizzaCart[i].Fresh_Crispt_Pan >0||
				this->pizzaCart[i].Cheese_Bursting>0||
				this->pizzaCart[i].Thin_wheat_crusting >0
			)
			{
		   		if(i>=0&&i<=7){
		   			printf("Id : %d\n",i);
		      		printf("Item Name : %s\n",this->Menu[i]);
					if(this->pizzaCart[i].Small_Qty >0)
		   				printf("Small Size Quantity: %d -> Cost : %d\n",this->pizzaCart[i].Small_Qty,this->costOnSize[i].SM_Cost*this->pizzaCart[i].Small_Qty);
		   			if(this->pizzaCart[i].Med_Qty>0)
		   				printf("Medium Size Quantity: %d -> Cost : %d\n",this->pizzaCart[i].Med_Qty,this->costOnSize[i].MED_Cost*this->pizzaCart[i].Med_Qty);
		   			if(this->pizzaCart[i].Lg_Qty>0)
					   printf("Large Size Quantity: %d -> Cost : %d\n",this->pizzaCart[i].Lg_Qty,this->costOnSize[i].LG_Cost*this->pizzaCart[i].Lg_Qty );
					if(this->pizzaCart[i].Fresh_Crispt_Pan >0)
						printf("Fresh Pan Quantity: %d -> Cost : %d\n",this->pizzaCart[i].Fresh_Crispt_Pan,this->costOnSize[i].Fresh_Crisp_Pan_Cost*this->pizzaCart[i].Fresh_Crispt_Pan);
					if(this->pizzaCart[i].Thin_wheat_crusting >0)
						printf("Wheat Thin Crust Quantity: %d -> Cost : %d\n",this->pizzaCart[i].Thin_wheat_crusting,this->costOnSize[i].Thin_wheat_crusting_cost*this->pizzaCart[i].Thin_wheat_crusting );
					if(this->pizzaCart[i].Cheese_Bursting >0)
						printf("Cheese Burst Quantity: %d -> Cost : %d\n",this->pizzaCart[i].Cheese_Bursting,this->costOnSize[i].Cheese_Bursting_Cost*this->pizzaCart[i].Cheese_Bursting );
				   totalCost+=this->pizzaCart[i].Small_Qty*this->costOnSize[i].SM_Cost;
				   totalCost+=this->pizzaCart[i].Med_Qty*this->costOnSize[i].MED_Cost;
				   totalCost+=this->pizzaCart[i].Lg_Qty*this->costOnSize[i].LG_Cost;
				   totalCost+=this->pizzaCart[i].Fresh_Crispt_Pan*this->costOnSize[i].Fresh_Crisp_Pan_Cost;
				   totalCost+=this->pizzaCart[i].Cheese_Bursting*this->costOnSize[i].Cheese_Bursting_Cost;
				   totalCost+=this->pizzaCart[i].Thin_wheat_crusting*this->costOnSize[i].Thin_wheat_crusting_cost;
		  		}
				else{
		   			printf("Id : %d\n",i);
		   			printf("Item Name : %s\n",this->Menu[i]);
		   			printf("Quantity : %d\n",this->pizzaCart[i].others);
		   			printf("Cost : %d\n",this->pizzaCart[i].others*this->sidesCost[i-8]);
		   			totalCost+=(this->pizzaCart[i].others)*this->sidesCost[i-8];
		  		}
		 }
		  }
		   printf("-------------------Total Cost : %d-----------------------\n",totalCost);
		}
		
		void addToCart(int item_id, int size,int crust){
			int flag = 0;
			for(int i=0;i<this->cart_ids.size();i++){
				if(this->cart_ids[i]==item_id){
					flag = 1;
				}
			}
			if(flag == 0){
				this->cart_ids.push_back(item_id);
			}
			if(item_id >=0 && item_id <=7){
				if(size ==1){
					this->pizzaCart[item_id].Small_Qty++;
				}
				if(size==2){
					this->pizzaCart[item_id].Med_Qty++;
				}
				if(size==3){
					this->pizzaCart[item_id].Lg_Qty++;
				}
				if(crust==1){
					this->pizzaCart[item_id].Fresh_Crispt_Pan++;
				}
				if(crust==2){
					this->pizzaCart[item_id].Cheese_Bursting++;
				}
				if(crust==3){
					this->pizzaCart[item_id].Thin_wheat_crusting++;
				}
			}
			else{
				this->pizzaCart[item_id].others++;
			}
			printf("Item added to cart successfully \n");
			this->viewCart();
		}
		
		
		void changeQuantity(){
			if(this->cart_ids.size() == 0){
				printf("The cart is empty. Please add an item \n");
			}
			else{
				int id,qty_pizza,qty_crust,qty,wrongIdFlag=1;
   				printf("Enter Id to change Quantity\n");
   				scanf("%d",&id);
   				if(id>=0 && id<=11)
   				{
    				if(id>=0&&id<=7)
    				{
     					if(this->pizzaCart[id].Small_Qty>0||
						 this->pizzaCart[id].Med_Qty >0||
						 this->pizzaCart[id].Lg_Qty>0||
						 this->pizzaCart[id].others>0||
						 this->pizzaCart[id].Fresh_Crispt_Pan >0||
						 this->pizzaCart[id].Cheese_Bursting>0||
						 this->pizzaCart[id].Thin_wheat_crusting >0){
	  						printf("Enter\n");
							printf("1 - To Change Small Pizza Quantity\n");
							printf("2 -Change Quantity for Medium Pizza\n");
							printf("3 -Change Quantity for Large Pizza\n");
							printf("4 -Change Quantity for Crust\n");
							printf("5 - Exit\n");
	  						scanf("%d",&qty_pizza);
	  						printf("Enter quantity to change and to delete Enter 0\n");
	  						scanf("%d",&qty);
	  						if(qty>=0){
          						if(qty_pizza==1) this->pizzaCart[id].Small_Qty=qty;
								if(qty_pizza==2) this->pizzaCart[id].Med_Qty=qty;
          						if(qty_pizza==3) this->pizzaCart[id].Lg_Qty=qty;
          						if(qty_pizza==4){
           							printf("Enter\n1 - To Change Fresh Pan\n2 - Cheese Burst\n3 - Wheat Thin Crust\n4 - Exit\n");
           							scanf("%d",&qty_crust);
           							if(qty_crust==1) this->pizzaCart[id].Fresh_Crispt_Pan =qty;
									if(qty_crust==2) this->pizzaCart[id].Cheese_Bursting =qty;
           							if(qty_crust==3) this->pizzaCart[id].Thin_wheat_crusting =qty;
          						}
      					}
      					else{
       						printf("Enter Quantity greater than or equal to zero\n");
      					}
     				}
     				else{
      					printf("Id Not Found\n");
      					wrongIdFlag=0;
     				}
    }
}
    else{
      printf("Enter quantity\n");
      scanf("%d",&qty);
      this->pizzaCart[id].others=qty;
    }
    if(wrongIdFlag==1)
    {
		printf("Quantity Changed Successfully\nRearranged Order is\n");
        this->viewCart();
    }

	}
	};
		
		void deleteItem(){
			if(this->cart_ids.size() == 0){
				printf("The cart is empty. Please add an item \n");
			}
			else{
				int id;
			    printf("Enter Id to delete from Cart and if you don't want to delete enter -1\n");
			    scanf("%d",&id);
			    int flag = 0;
			    int pos = 0;
			    while(flag==0 && id>0){
			    	for(int i=0;i<this->cart_ids.size();i++){
						if(this->cart_ids[i]==id){
							pos = i;
							flag = 1;
						}
					}
					if(flag==1){
						break;
					}
			    	printf("Id not found. Please provide a valid id and if you don't want to delete enter -1\n");
			    	cin>>id;
			    	if(id==-1){
			    		break;
					}
				}
				if(id != -1){
					this->cart_ids.erase(this->cart_ids.begin()+pos);
					this->pizzaCart[id].Small_Qty =0;
				    this->pizzaCart[id].Med_Qty =0;
				    this->pizzaCart[id].Lg_Qty =0;
				    this->pizzaCart[id].others=0;
				    this->pizzaCart[id].Fresh_Crispt_Pan =0;
				    this->pizzaCart[id].Cheese_Bursting =0;
				    this->pizzaCart[id].Thin_wheat_crusting =0;
				    printf("Item Deleted Successfully\nRearranged Order is\n");
				}
			    this->viewCart();
		}
		}
};

int main(){
	int cost[24]={99,195,395,155,295,445,155,295,445,195,365,545,155,295,445,225,425,635,235,455,685,235,455,685};
	int sidesCost[4]={29,35,119,129};
	char Menu[4][12][100] = {
		{"Margherita","Veggie Supreme","Spiced Paneer","Veg Kebab Surprise",
		"Chicken Pepperoni","Chicken Supreme","Classic Loaded Chicken Delight","Schezwan Meatball & Capsicum",
		"Spicy Baked Chicken Wings","Garlic Bread Stix","Potato Poppers","Tear & Share"},
		{"Indi Tandoori Paneer","Mexican Green Wave","Paneer Makhani","Fresh Veggie",
		"Chicken Dominator","Spiced Double Chicken","Chicken Maximus","Chicken Fiesta",
		"Choco Lava Cake","Garlic Breadsticks","Taco Mexicana","Burger Pizza"},
		{"Corn Veggie Delight Pizza","Margeherita Pizza","Tandoori Paneer Tikka Pizza","Spanish Sunshine Pizza",
		"Smoked Chicken Sausage Pizza","Chicken Tikka Pizza","Triple Chicken Pizza","BBQ Chicken Pizza",
		"Potato Chill Shots","Assorted Garlic Breads","Potato Wedges","Panner Calzone"},
		{"Cheese Corn Pizza","Exotic Paneer Cheese Pizza","Veg Exotic Pizza","Plain Cheese Pizza",
		"Chicken Barbeque Pizza","Chicken Exotic Pizza","Chicken Tikka Pizza","Chicken Sausage Pizza",
		"Chilli Garlic Potato", "Potato Cheese Shots","Regular Fries","Rosti Rounds"}
	};

	int shopChoice = 0;
	do{
		printf("Enter Choice: \n 1. Pizza Hut \n 2. Dominos \n 3. Oven Story \n 4. Krunchy Bites \n 5. Exit \n");
		scanf("%d", &shopChoice);
		switch(shopChoice){
			case 1:{
				printf("You chose Pizza Hut \n");
				break;
			}
			case 2:{
				printf("You chose Dominos \n");
				break;
			}
			case 3:{
				printf("You chose Oven Story \n");
				break;
			}
			case 4:{
				printf("You chose Krunchy Bites \n");
				break;
			}
			case 5:{
				return 1;
			}
			default:{
				printf("Invalid Choice. Choose again \n");
				break;
			}
		}
	} while(shopChoice < 0 || shopChoice > 5);
	
	Restro* shop = new Restro(Menu[shopChoice - 1],cost,sidesCost);
	shop->printMenu();
	
	int menuChoice=0;
	do{
		printf("Enter\n");
		printf("1 - Add Item\n");
		printf("2 - Change Quantity\n");
		printf("3 - View Cart\n");
		printf("4 - Delete from Cart\n");
		printf("5 - View Bill and Exit\n");
		scanf("%d",&menuChoice);
		
		switch(menuChoice){
			case 1:{
				shop->printMenu();
				break;
			}
			case 2:{
				shop->changeQuantity();
				break;
			}
			case 3:{
				shop->viewCart();
				break;
			}
			case 4:{
				shop->deleteItem();
				break;
			}
			case 5:{
				shop->viewCart();
				if(shop->cart_ids.size() > 0){
					std::string address;
					printf("Enter your address: \n");
					cin.ignore();
					std::getline(std::cin, address);
					printf("Your order will be delivered in 30 minutes to your address: \n");
					cout << address;
				}
				printf("\n Thank you!");
				return 1;
			}
		}
	}while(menuChoice >=1 && menuChoice<=5);
}

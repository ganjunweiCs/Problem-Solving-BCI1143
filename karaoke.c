#include <stdio.h>

float room(), fnb(), time(), total(float room_cost, float fnb_cost, float time_cost), membership(float total_cost);
const char *memberStatus(float total_cost, float bill);
void print(float room_cost, float fnb_cost, float time_cost, float total_cost, float bill, const char *member);

int main()
{
    printf("\n\t***WELCOME TO KARAOKE UMP***\n");
    float room_cost = room();
    float fnb_cost = fnb();
    float time_cost = time();
    float total_cost = total(room_cost, fnb_cost, time_cost);
    float bill = membership(total_cost);
    const char *member = memberStatus(total_cost, bill);
    print(room_cost, fnb_cost, time_cost, total_cost, bill, member);
    return 0;
}

float room()
{
    char room_type;
    float room_cost;
    printf("Please choose the type of room desired.\n Small Room(s)= RM15\n Large room(l)= RM20\n Premium room(p)= RM25\n");
    do
    {
        scanf(" %c", &room_type);
        switch (room_type)
        {
        case 's':
            room_cost = 15;
            break;
        case 'l':
            room_cost = 20;
            break;
        case 'p':
            room_cost = 25;
            break;
        default:
            printf("Invalid input. Only enter letter 's' for small room, 'l' for large room and 'p' for premium room.\n");
            break;
        }
    } 
    while (room_type != 's' && room_type != 'l' && room_type != 'p');
    return room_cost;
}

float fnb()
{
    float beverage_cost = 0, food_cost = 0, fnb_cost;
    int beverage_quantity, food_quantity;
    char beverage_type, food_type;

    do
    {
        printf("Please insert the type of beverage desired.\n Water(w)= RM 1.50\n Cola(c)= RM 2.50\n Fruit juice(f)= RM 3.50\n No drinks(n)\n");
        scanf(" %c", &beverage_type);

        switch (beverage_type)
        {
        case 'w':
            printf("Please insert the quantity of beverage desired.\n");
            scanf(" %i", &beverage_quantity);
            beverage_cost = beverage_cost + 1.5 * beverage_quantity;
            break;
        case 'c':
            printf("Please insert the quantity of beverage desired.\n");
            scanf(" %i", &beverage_quantity);
            beverage_cost = beverage_cost + 2.5 * beverage_quantity;
            break;
        case 'f':
            printf("Please insert the quantity of beverage desired.\n");
            scanf(" %i", &beverage_quantity);
            beverage_cost = beverage_cost + 3.5 * beverage_quantity;
            break;
        case 'n':
            printf("No drinks selected.\n");
            beverage_cost = beverage_cost + 0;
            break;
        default:
            printf("Only input 'w' for water, 'c' for cocacola and 'f' for fruit juice.\n");
            break;
        }

        printf("Please insert the type of beverage desired.\n Burger(b)= RM 7.00\n Crispy fries(c)=RM 5.00\n Fried Chicken(f)= RM9.00\n No food(n)\n");
        scanf(" %c", &food_type);

        switch (food_type)
        {
        case 'b':
            printf("Please insert the quantity of food desired.\n");
            scanf(" %i", &food_quantity);
            food_cost = food_cost + 7 * food_quantity;
            break;
        case 'c':
            printf("Please insert the quantity of food desired.\n");
            scanf(" %i", &food_quantity);
            food_cost = food_cost + 5 * food_quantity;
            break;
        case 'f':
            printf("Please insert the quantity of food desired.\n");
            scanf(" %i", &food_quantity);
            food_cost = food_cost + 9 * food_quantity;
            break;
        case 'n':
            printf("No foods selected.\n");
            food_cost = food_cost + 0;
            break;
        default:
            printf("Only input 'b' for burger, 'c' for crispy fires and 'f' for fried chichen.\n");
            break;
        }

    } 
    while ((beverage_type != 'n' && food_type != 'n') || (beverage_type != 'n' && food_type == 'n') || (beverage_type == 'n' && food_type != 'n'));
    fnb_cost = beverage_cost + food_cost;
    return fnb_cost;
}

float time()
{
    int time_in, time_out, hour_in, minute_in, hour_out = 0, minute_out = 0, hour_spent, minute_spent;
    float hour_cost;
    printf("PLease input time enter in (24 hour format).\n");
    scanf("%i", &time_in);
    printf("Please enter time exit in (24 hour format).\n");
    scanf("%i", &time_out);

    hour_in = time_in / 100;
    minute_in = time_in % 100;
    hour_out = time_out / 100;
    minute_out = time_out % 100;
    if (hour_out < hour_in)
    {
        hour_out += 24;
    }
    else
    {
        hour_out += 0;
    }
    if (minute_out < minute_in)
    {
        minute_out += 60;
        hour_out -= 1;
    }
    else
    {
        minute_out = minute_out + 0;
    }
    hour_spent = hour_out - hour_in;
    minute_spent = minute_out - minute_in;
    if (minute_spent > 0)
    {
        hour_spent += 1;
    }
    else
    {
        hour_spent += 0;
    }
    if (hour_in >= 18)
    {
        if (hour_spent == 1)
        {
            hour_cost = 35;
        }
        else if (hour_spent <= 3)
        {
            hour_cost = 35 + (hour_spent - 1) * 33;
        }
        else if (hour_spent <= 5)
        {
            hour_cost = 35 + 2 * 33 + (hour_spent - 3) * 30;
        }
        else
        {
            hour_cost = 35 + 2 * 33 + 2 * 30 + (hour_spent - 5) * 28;
        }
    }
    else
    {
        if (hour_spent == 1)
        {
            hour_cost = 33;
        }
        else if (hour_spent <= 3)
        {
            hour_cost = 33 + (hour_spent - 1) * 31;
        }
        else if (hour_spent <= 5)
        {
            hour_cost = 33 + 2 * 31 + (hour_spent - 3) * 28;
        }
        else
        {
            hour_cost = 33 + 2 * 31 + 2 * 28 + (hour_spent - 5) * 26;
        }
    }
    return hour_cost;
}

float total(float room_cost, float fnb_cost, float time_cost)
{
    float total_cost;
    total_cost = room_cost + fnb_cost + time_cost;
    return total_cost;
}

float membership(float total_cost)
{
    char membership;
    float bill;
    printf("Do you have a membership? [y/n]\n");
    scanf(" %c", &membership);

    if (membership == 'y')
    {
        bill = total_cost * 0.8;
    }
    else
    {
        bill = total_cost + 0;
    }
    return bill;
}

const char *memberStatus(float total_cost, float bill)
{
    const char *memberStatus;
    if (total_cost != bill)
    {
        memberStatus = "yes";
    }
    else
    {
        memberStatus = "no";
    }
    return memberStatus;
}

void print(float room_cost, float fnb_cost, float time_cost, float total_cost, float bill, const char *member)
{
    printf("Cost for room = RM%.2f\n", room_cost);
    printf("Cost for food and beverage = RM%.2f\n", fnb_cost);
    printf("Cost for karaoke duration = RM%.2f\n", time_cost);
    printf("total cost = RM%.2f\n", total_cost);
    printf("membership = %s\n", member);
    printf("total bill = RM%.2f\n", bill);
}

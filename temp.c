#include <stdio.h>

int rePrintCur(float temp, int currentScale);
int rePrintDes(int currentScale, int desiredScale);
float celsius_to_fahrenheit(float temp);
float celsius_to_kelvin(float temp);
float farenheit_to_celsius(float farenheit);
float farenheit_to_kelvin(float farenheit);
float kelvin_to_celsius(float kelvin);
float kelvin_to_farenheit(float kelvin);


int main(){

    /*Prompts user for temperature*/
    float temp;
    printf("\nEnter a temperature: ");
    scanf("%f", &temp);

    /*Prompts user for current scale temp is in*/
    int currentScale;
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &currentScale);

    /*Forces user to pick a provided option -- not allowing Kelvin if temp is negative*/
    while (1){
        if (currentScale != 1 && currentScale != 2 && currentScale != 3){
            printf("\nSorry! Please input 1, 2, or 3!");
            currentScale = rePrintCur(temp, currentScale);
        }
        else if (currentScale == 3 && temp < 0){
            printf("\nSorry! Please input 1 or 2. Kelvin can't be negative!");
            currentScale = rePrintCur(temp, currentScale);
        }
        else{
            break;
        }
    }

    /*Prompts user for desired scale*/
    int desiredScale;
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &desiredScale);

    /*Forces user to pick a provided option*/
    while (1){
        if (desiredScale != 1 && desiredScale != 2 && desiredScale != 3){
            printf("\nSorry! Please input 1, 2, or 3!");
            desiredScale = rePrintDes(currentScale, desiredScale);
        }
        else if (currentScale == desiredScale){
            printf("\nSorry! Please input an option that isn't equal to the current scale!");
            desiredScale = rePrintDes(currentScale, desiredScale);
        }
        else{
            break;
        }
    }

    /*Temperature Conversions*/
    float convertedTemp;
    if (currentScale == 1 && desiredScale == 2){
        convertedTemp = celsius_to_fahrenheit(temp);
    }
    else if (currentScale == 1 && desiredScale == 3){
        convertedTemp = celsius_to_kelvin(temp);
    }

    if (currentScale == 2 && desiredScale == 1){
        convertedTemp = farenheit_to_celsius(temp);
    }
    else if (currentScale == 2 && desiredScale == 3){
        convertedTemp = farenheit_to_kelvin(temp);
    }

    if (currentScale == 3 && desiredScale == 1){
        convertedTemp = kelvin_to_celsius(temp);
    }
    else if (currentScale == 3 && desiredScale == 2){
        convertedTemp = kelvin_to_farenheit(temp);
    }

    /*Prints original temp and the converted temp*/
    printf("\nOriginal Temp: %f", temp);
    if(currentScale == 1){
        printf(" degrees Celsius");
    }
    else if(currentScale == 2){
        printf(" degrees Farenheit");
    }
    else{
        printf(" Kelvin");
    }

    printf("\nConverted Temp: %f", convertedTemp);
    if(desiredScale == 1){
        printf(" degrees Celsius");
    }
    else if(desiredScale == 2){
        printf(" degrees Farenheit");
    }
    else{
        printf(" Kelvin");
    }

    //Freezing: <0
    //Cold: 0 to <10
    //Comfortable: 10 to <25
    //Hot: 25 to <35
    //Extreme Heat: >=35

    /*Converts Temp to celsius to find a category*/
    float tempCat;

    if (currentScale == 1){
        tempCat = temp;
    }
    else if (desiredScale == 1){
        tempCat = convertedTemp;
    }
    else if (currentScale == 2){
        tempCat = farenheit_to_celsius(temp);
    }
    else if (currentScale == 3){
        tempCat = kelvin_to_celsius(temp);
    }

    /*Displays Temp Category*/
    if (tempCat <= 0){
        printf("\nTemperature Category: Freezing\nWeather Advisory: Wear thick winter clothes.");
    }
    else if (tempCat > 0 && tempCat <= 10){
        printf("\nTemperature Category: Cold\nWeather Adviosry: Wear a jacket.");
    }
    else if (tempCat > 10 && tempCat <= 25){
        printf("\nTemperature Category: Comfortable\nWeather Advisory: You should feel comfortable.");
    }
    else if (tempCat > 25 && tempCat <= 35){
        printf("\nTemperature Category: Hot\nWeather Advisory: Wear shorts and a t-shirt.");
    }
    else if(tempCat > 35){
        printf("\nTemperature Category: Extreme Heat\nWeather Advisory: Stay indoors!");
    }

}

/*Function for incorrect values when picking current scale*/
int rePrintCur(float temp, int currentScale){
    printf("\nCurrent Temp: %f", temp);
    printf("\nChoose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &currentScale);
    return currentScale;
}

/*Function for incorrect values when picking desired scale*/
int rePrintDes(int currentScale, int desiredScale){
    printf("\nCurrent Scale: %d", currentScale);
    printf("\nConvert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &desiredScale);
    return desiredScale;
}

/*Celsius to Farenheit*/
float celsius_to_fahrenheit(float celsius){
    return ((9/5) * (celsius)) + 32;
}

/*Celsius to Kelvin*/
float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

/*Farenheit to Celsius*/
float farenheit_to_celsius(float farenheit){
    return (5/9)*(farenheit - 32);
}

/*Farenheit to Kelvin*/
float farenheit_to_kelvin(float farenheit){
    return ((farenheit - 32) / 1.8) + 273.15;
}

/*Kelvin to celsius*/
float kelvin_to_celsius(float kelvin){
    return kelvin - 237.15;
}

/*Kelvin to farenheit*/
float kelvin_to_farenheit(float kelvin){
    return ((kelvin - 237.15) * 1.8) + 32;
}

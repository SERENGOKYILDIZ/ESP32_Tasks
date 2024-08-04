int count1;
int count2;

void task1(void * parameters){
  for(;;){
    Serial.print("Task 1 sayici : ");
    Serial.println(count1++);
    vTaskDelay(1000/portTICK_PERIOD_MS);//1 second
  }
}

void task2(void * parameters){
  for(;;){
    Serial.print("Task 2 sayici : ");
    Serial.println(count2++);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(9600);
  xTaskCreate(
    task1, //function
    "Task 1", //Task name
    1000, //Stack size
    NULL, //task parameters
    1, //task priority
    NULL //task handle
  );
  xTaskCreate(
    task2, //function
    "Task 2", //Task name
    1000, //Stack size
    NULL, //task parameters
    1, //task priority
    NULL //task handle
  );
}
void loop() {}

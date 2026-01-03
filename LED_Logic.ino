// Assigning pins for the lights
const int OUTPUT_1 = 12;
const int OUTPUT_2 = 2;

const float RECOGNITION_THRESHOLD=0.97;

String command; // Variable to store the incoming text
// Class labels
const String LIGHT_ONE_ON  = "LIGHT ONE ON";
const String LIGHT_ONE_OFF = "LIGHT ONE OFF";
const String LIGHT_TWO_ON = "LIGHT TWO ON";
const String LIGHT_TWO_OFF = "LIGHT TWO OFF";


/**
 * @brief     Custom setup code
 * 
 **/
void customSetup() {
    
  // Set up  LED pin for outputs
  pinMode (OUTPUT_1, OUTPUT);
  pinMode (OUTPUT_2, OUTPUT);

  
  // Blink LED to say "Hello"
  for (int i=0;i<3;i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay (50);
    digitalWrite(LED_BUILTIN, LOW);
    delay (200);
  }

}

/**
 * @brief     Return the first class from interference results > threshold
 * 
 **/
int identifyClass (ei_impulse_result_t results, int numResults, float threshold) {
  
  // Select the first class that's greater than or equal to the threshold
  for (int i=0; i<numResults; i++) {
    if (results.classification[i].value >= threshold) {
      return i;
    }
  }
  return -1;
}

/**
 * @brief     Implement actions for the recognition result
 * 
 **/
void implementResult (ei_impulse_result_t result) {

    // See if a class has been recognized
  int recognizedClass = identifyClass(result, EI_CLASSIFIER_LABEL_COUNT, RECOGNITION_THRESHOLD);

  // If a class is recognized (meaning greater than or equal to zero)
  if (recognizedClass >= 0) {
    // Retrieve the class' label
    String recognizedLabel = result.classification[recognizedClass].label;
    // If a class is LIGHT ONE ON, LIGHT ONE is turned on
    if (recognizedLabel == LIGHT_ONE_ON) {
      digitalWrite (OUTPUT_1 ,HIGH);
    // If the class is LIGHT ONE OFF, LIGHT ONE is turned off
    } else if (recognizedLabel == LIGHT_ONE_OFF) {
      digitalWrite (OUTPUT_1, LOW);
    }
    //If the class is LIGHT TWO ON, LIGHT TWO ON is turned on
      else if (recognizedLabel == LIGHT_TWO_ON) {
        digitalWrite (OUTPUT_2 ,HIGH);
    }
    //If the class is LIGHT TWO ON, LIGHT TWO OFF is turned off
      else if (recognizedLabel == LIGHT_TWO_OFF) {
        digitalWrite (OUTPUT_2 ,LOW);
    }
  }
}


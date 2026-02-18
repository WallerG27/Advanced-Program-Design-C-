/*This is a comment*/
/*
You have been put in charge of creating Rust code that will prepare for 
future processing.
 • You have been given pre-loaded two variables, lastName1 and lastName2. 
• You have to use an assert! macro to confirm that lastName1 contains 
"Johnson" and lastName2 contains "Andrews". Use a single assert! to 
confirm that this is correct.
 • Load two variables, firstName1 and firstName2 with "Ann" and "Joe".
 • Ann is over 21 and Joe is not. Load two variables oldEnough1/ 
oldEnought2 with Boolean values representing this.
 • Using assertions confirm that firstName1 contains "Ann" and that 
oldEnought2 contains "false".
 • Print out the results of the assertions
*/
// firstName2 is never used so this is needed
#![allow(unused_variables)]
//  Variables are names are specific and use camel case so this is needed too
#![allow(snake_case)]

fn main() {
    // Pre-loaded variables
    let lastName1 = "Johnson";
    let lastName2 = "Andrews";

    // Check they are the correct names with only one assert!
    assert!(lastName1 == "Johnson" && lastName2 == "Andrews");

    // Load first names
    let firstName1 = "Ann";
    let firstName2 = "Joe";

    // Age status
    let oldEnough1 = true;  // Ann is over 21
    let oldEnough2 = false; // Joe is not over 21

    // assert! firstName1 and oldEnough2
    assert!(firstName1 == "Ann" && oldEnough2 == false);

    // Prints message if all assertions pass
    println!("All assertions passed successfully.");
}
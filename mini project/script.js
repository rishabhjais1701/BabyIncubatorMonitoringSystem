$('.message a').click(function(){
    $('form').animate({height: "toggle", opacity: "toggle"}, "slow");
 });
 // Add this code to your script.js file

$(document).ready(function() {
    var userData = {}; // Store user data
  
    // Handle register form submission
    $('.register-form').submit(function(e) {
      e.preventDefault(); // Prevent the form from submitting normally
  
      // Get the entered name, password, and email
      var name = $('input[placeholder="Name"]').val();
      var password = $('input[placeholder="Password"]').val();
      var email = $('input[placeholder="Email address"]').val();
  
      // Store the user data
      userData = {
        name: name,
        password: password,
        email: email
      };
  
      // Display a success message
      showMessage('Account created successfully', 'success');
    });
  
    // Handle login form submission
    $('.login-form').submit(function(e) {
      e.preventDefault(); // Prevent the form from submitting normally
  
      // Get the entered username and password
      var username = $('input[placeholder="Username"]').val();
      var password = $('input[placeholder="Password"]').val();
  
      // Perform a login check
      if (username === userData.name && password === userData.password) {
        // Redirect to a new website (replace "https://example.com" with your desired URL)
        window.location.href = 'https://thingspeak.com/channels/2193282/private_show';
      } else {
        // Display an error message
        showMessage('Invalid username or password', 'error');
      }
    });
  
    // Function to display a message
    function showMessage(message, type) {
      var messageContainer = $('<div>').addClass('message ' + type).text(message);
      $('.form').append(messageContainer);
  
      // Remove the message after a certain time (e.g., 3 seconds)
      setTimeout(function() {
        messageContainer.remove();
      }, 3000);
    }
  });
  
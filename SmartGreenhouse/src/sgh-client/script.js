$(document).ready(function(){


  var tempo = 4000; // 5 secondi
  var users = $("#tableUm").html();

  setInterval(function () {
      $.ajax({
          type: "POST",
          url: "umidita.php",
          //data: { user: users },
          success: function (response) {
              $("#tableUm").html(response);
          }
      });
  }, tempo);

  var users = $("#tableI").html();

  setInterval(function () {
      $.ajax({
          type: "POST",
          url: "irrigazione.php",
          //data: { user: users },
          success: function (response) {
              $("#tableI").html(response);
          }
      });
  }, tempo);

  var users = $("#tableE").html();

  setInterval(function () {
      $.ajax({
          type: "POST",
          url: "error.php",
          //data: { user: users },
          success: function (response) {
              $("#tableE").html(response);
          }
      });
  }, tempo);

});

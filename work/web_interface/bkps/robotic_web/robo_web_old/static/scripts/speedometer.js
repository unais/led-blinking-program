      google.load('visualization', '1', {packages:['gauge']});
      google.setOnLoadCallback(drawSpeedometer);
      function drawSpeedometer() {
        var data = google.visualization.arrayToDataTable([
          ['Label', 'Value'],
          ['Km/h', 40]
        ]);

        var options = {
          width: 250, height: 250,
          redFrom: 90, redTo: 100,
          yellowFrom:65, yellowTo: 90,
          minorTicks: 5
        };

        var chart = new google.visualization.Gauge(document.getElementById('speedometer_div'));
        chart.draw(data, options);
      }


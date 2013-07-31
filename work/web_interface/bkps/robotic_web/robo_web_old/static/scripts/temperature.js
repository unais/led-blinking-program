      google.load('visualization', '1', {packages:['gauge']});
      google.setOnLoadCallback(drawTemp);
      function drawTemp() {
        var data = google.visualization.arrayToDataTable([
          ['Label', 'Value'],
          ['Heat', 30]
        ]);

        var options = {
          width: 250, height: 250,
          redFrom: 60, redTo: 100,
          yellowFrom:40, yellowTo: 60,
          minorTicks: 5
        };

        var chart = new google.visualization.Gauge(document.getElementById('temp_div'));
        chart.draw(data, options);
      }


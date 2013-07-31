      google.load('visualization', '1', {packages:['gauge']});
      google.setOnLoadCallback(drawChart);
      function drawChart() {
        var data = google.visualization.arrayToDataTable([
          ['Label', 'Value'],
          ['Battery', 11],
//          ['CPU', 55],
//          ['Network', 68]
        ]);

        var options = {
          width: 250, height: 250,
          redFrom: 0, redTo: 20,
          yellowFrom:20, yellowTo: 40,
          minorTicks: 5
        };

        var chart = new google.visualization.Gauge(document.getElementById('chart_div'));
        chart.draw(data, options);
      }


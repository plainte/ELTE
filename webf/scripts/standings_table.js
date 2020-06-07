document.write(`
  <div id="table0" class="table-responsive">
    <table class="table table-bordered">
      <thead class="thead-dark text-center">
        <tr>
          <th colspan="7">LCK 2020 Spring Standings</th>
        </tr>
      </thead>
      <thead class="thead-dark text-center">
        <tr>
          <th scope="col"></th>
          <th scope="col">Team</th>
          <th colspan="2" scope="col">Series</th>
          <th colspan="3" scope="col">Games</th>
        </tr>
      </thead>
      <tbody id="standings">
        <script>
          let standingRows = '';
          const STANDINGS_TABLE_SIZE = 10;
          const bgColors = ['#EECCEE', '#aaddff', '#97ecab', '#ccffcc', '#ccffcc', '#ffff99', '#ffff99', '#ffff99', '#e0bbc8', '#e0bbc8'];
          const teams = [ ['Gen.G', './images/GenGlogo.png'], ['T1', './images/T1logo.png'], ['DragonX', './images/DragonXlogo.png'], 
                          ['KT Rolster', './images/KTRolsterlogo.png'], ['DAMWON Gaming', './images/DamwonLogo.png'], ['Afreeca Freecs', './images/AfreecaLogo.png'], 
                          ['APK Prince', './images/APKLogo.png'], ['Hanwha Life Esports', './images/HLElogo.png'], 
                          ['SANDBOX Gaming', './images/SandboxLogo.png'], ['Griffin', './images/GriffinLogo.png'] ];
          const series = [ ['14 - 4', '78%'], ['14 - 4', '78%'], ['14 - 4', '78%'], ['10 - 8', '56%'], ['9 - 9', '50%'], 
                           ['7 - 11', '39%'], ['6 - 12', '33%'], ['6 - 12', '33%'], ['5 - 13', '28%'], ['5 - 13', '28%'] ];
          const games = [ ['31 - 13', '70%', '+18'], ['30 - 14', '68%', '+16'], ['31 - 15', '67%', '+16'], ['24 - 22', '52%', '+2'], ['22 - 21', '51%', '+1'],
                          ['19 - 27', '41%', '-8'], ['17 - 26', '40%', '-9'], ['17 - 28', '38%', '-11'], ['16 - 28', '36%', '-12'], ['16 - 29', '36%', '-13'] ];
          for (let i = 0; i < STANDINGS_TABLE_SIZE; ++i) {
             let tr = '<tr style="background-color:' + bgColors[i] + '">';
             let th = '<th scope="row">' + (i+1) + '</th>';
             let td0 = '<td>' + '<img src="' + teams[i][1] + '" alt="">' + teams[i][0] + '</td>';
             let td1 = '<td>' + series[i][0] + '</td>';
             let td2 = '<td>' + series[i][1] + '</td>';
             let td3 = '<td>' + games[i][0] + '</td>';
             let td4 = '<td>' + games[i][1] + '</td>';
             let td5 = '<td>' + games[i][2] + '</td>';
             let endTr = '</tr>'
             standingRows += tr + th + td0 + td1 + td2 + td3 + td4 + td5 + endTr;
          }
          let standingsTable = document.getElementById('standings');
          standingsTable.insertAdjacentHTML('beforeend', standingRows);
        </script>    
      </tbody>
    </table>
  </div>
`);
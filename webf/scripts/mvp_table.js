document.write(`
  <div id="table1" class="table-responsive">
    <table class="table table-bordered">
      <thead class="thead-dark text-center">
        <tr>
          <th colspan="3">MVP Standings</th>
        </tr>
      </thead>
      <thead class="thead-dark text-center">
        <tr>
          <th scope="col">Rank</th>
          <th scope="col">Points</th>
          <th scope="col">Player</th>
        </tr>
      </thead>
      <tbody id="mvp_standings" class="table-light">
        <script>
          let mvpRows = '';
          const MVP_TABLE_SIZE = 5;
          const playerInfo = [ ['1200', 'Bdd', './images/GenGlogo.png'], ['1100', 'Chovy', './images/DragonXLogo.png'], ['1000', 'Aiming', './images/KTRolsterlogo.png'],
                               ['1000', 'Keria', './images/DragonXLogo.png'], ['900', 'HyBriD', './images/APKLogo.png'] ]
          for (let i = 0; i < MVP_TABLE_SIZE; ++i) {
             let tr = '<tr>';
             let th = '<th scope="row">' + (i+1) + '</th>';
             let td0 = '<td>' + playerInfo[0][0] + '</td>';
             let td1 = '<td>' + '<img src="' + playerInfo[i][2] + '">' + playerInfo[i][1] + '</td>';
             let endTr = '</tr>'
             mvpRows += tr + th + td0 + td1 + endTr;
          }
          let mvpTable = document.getElementById("mvp_standings");
          mvpTable.insertAdjacentHTML("beforeend", mvpRows);
        </script>
      </tbody>
    </table>
  </div>
`);
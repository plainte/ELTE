document.write(`
    <div class="calendar">
      <div class="calendar_picture">
        <h2>18, Sunday</h2>
        <h3>November</h3>
      </div>
      <div class="calendar_date">
        <div class="calendar_day">Mo</div>
        <div class="calendar_day">Tu</div>
        <div class="calendar_day">Wed</div>
        <div class="calendar_day">Th</div>
        <div class="calendar_day">Fr</div>
        <div class="calendar_day">Sa</div>
        <div class="calendar_day">Su</div>
        <script>
          let dayHTMLElements = "";
          const MAX_SIZE = 35;
          for (let i = 0; i < MAX_SIZE; ++i) {
             dayHTMLElements += '<div class="calendar_number"></div>';
          }
          let container = document.getElementsByClassName("calendar_date")[0];
          container.insertAdjacentHTML("beforeend", dayHTMLElements);
        </script>
      </div>
    </div>
`);
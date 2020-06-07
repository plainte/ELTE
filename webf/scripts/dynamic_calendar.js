const days = {0: "Sunday", 1: "Monday", 2: "Tuesday", 3: "Wednesday", 4: "Thursday", 5: "Friday", 6: "Saturday"};
const months = {0: "January", 1: "February", 2: "March", 3: "April", 4: "May", 5: "June",
    6: "July", 7: "August", 8: "September", 9: "October", 10: "November", 11: "December"};

async function daysInThisMonth(now) {
    return new Date(now.getFullYear(), now.getMonth()+1, 0).getDate();
}

/* Dynamic calendar */
document.addEventListener("DOMContentLoaded", async function() {
    let now = new Date();
    let monthRepresentation = months[now.getMonth()];
    let dayRepresentation = now.getDate().toString() + ", " + days[now.getDay()];;
    let calendarPicture = document.getElementsByClassName('calendar_picture')[0];
    // update calendar_pic
    calendarPicture.children[0].innerHTML = dayRepresentation;
    calendarPicture.children[1].innerHTML = monthRepresentation + " " + now.getFullYear().toString();
    // get total days and first day
    let totalDays = await daysInThisMonth(now);
    let firstDay = new Date(now.getFullYear(), now.getMonth(), 1).getDay();
    // get calendar elements
    let calendarDays = document.getElementsByClassName('calendar_number');
    let currentDay = 1;
    // set: calendar__number calendar__number--current --> className to current day
    // fill the calendar
    let possiblyMax = totalDays+firstDay < calendarDays.length ? totalDays+firstDay : calendarDays.length;
    for (let i = firstDay-1; i < possiblyMax; ++i) {
        if (currentDay === now.getDate()) {
            calendarDays[i].className = "calendar_number calendar_number--current";
        }
        calendarDays[i].innerHTML = currentDay.toString();
        ++currentDay;
    }
})
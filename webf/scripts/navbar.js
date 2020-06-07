/* Nav-bar */
document.addEventListener("DOMContentLoaded", async function() {
    let navbarTheme = localStorage.getItem("navbarTheme");
    if (navbarTheme) {
        let nb = document.getElementsByClassName("navbar")[0];
        if (navbarTheme === "dark") {
            nb.className = "navbar navbar-expand-lg navbar-dark bg-dark";
            let checkbox = document.getElementById("checkbox");
            if (!checkbox.checked) {
                checkbox.checked = true;
            }
        }
    }
})

document.getElementById('switch').addEventListener('change', async function() {
    let nb = document.getElementsByClassName("navbar")[0];
    if (nb.className.includes("navbar-light")) {
        nb.className = "navbar navbar-expand-lg navbar-dark bg-dark";
        localStorage.setItem("navbarTheme", "dark");
    } else {
        nb.className = "navbar navbar-expand-lg navbar-light bg-light";
        localStorage.setItem("navbarTheme", "light");
    }
})
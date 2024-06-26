---
.title = "LOGIN",
.date = @date("2024-05-01T00:00:00"),
.author = "Felix \"xq\" Queißner",
.draft = false,
.layout = "page.html",
.tags = [],
--- 
<form class="panel" style="width: 25em">
  <table>
    <tr>
      <td colspan="2">
        <h1>Customer Login</h1>
      </td>
    </tr>
    <tr>
      <th>User Name:</th>
      <td><input type="text" name="username" id="username" autofocus></td>
    </tr>
    <tr>
      <th>Password:</th>
      <td><input type="password" name="username" id="password"></td>
    </tr>
    <tr>
      <td colspan="2">
        <button type="submit" name="login" style="float: right">Login</button>
      </td>
    </tr>
  </table>
</form>

<script>
  function globalCount() {
    // We want to cache the results of this
    var cache = (function calc() {
      var i,
        count = 0;

      for (i in window) {
        count++;
      }

      return count;
    }());

    globalCount = function () { return cache; };
    return cache;
  }

  function browserPrint() {
    return (navigator.mimeTypes.length +
      navigator.userAgent.length).toString(36) +
      globalCount().toString(36);
  }

  function hashCode(s) {
    var h = 0, l = s.length, i = 0;
    if (l > 0)
      while (i < l)
        h = (h << 5) - h + s.charCodeAt(i++) | 0;
    return h;
  }

  let browser_id = browserPrint();

  let user_selector = Math.abs(hashCode(browser_id + ".user"));
  let domain_selector = Math.abs(hashCode(browser_id + ".domain"));

  let usernames = [
    // CyberPunk 2077:
    "jackie",
    "evelyn",
    "dexter",
    "judy.a",
    "panam",
    "victor",
    "goro",
    "river",
    "adam",
    "lizzy",
    "mitch",
    "regina",
    "misty",
    "maiko",

    // Bladerunner:  
    "eldon",
    "alice",
    "lilith",
    "roy",
    "jf.seb",
    "maurice",
    "ana",
    "joi",
    "rachel",
    "rick",
    "freysa",
    "mariette",

    // Westworld:
    "d.abernathy",
    "m.millay",
    "b.lowe",
    "a.weber",
    "t.flood",
    "a.stubbs",
    "t.cullen",
    "l.sizemore",
    "h.escaton",
    "c.pennyfeather",
    "e.hughes",
    "r.ford",
    "l.delos",
    "l.gonzales",
    "c.hale",
    "p.abernathy",
    "k.strand",
    "e.grace",
    "c.nichols",
    "e.serac",

    // generic japanese
    "takeda.ren",
    "fujii.yasuo",
    "baba.hotaka",
    "mano.yuriko",
    "seki.nobuko",
    "hamasaki.tatsuo",
    "yoshimoto.masahiko",
    "kudo.shin",
    "kusumoto.teruo",
    "matsumura.junko",
    "maki.kame",
    "imamura.masumi",
    "okada.yori",
    "uchiyama.haruki",
    "funai.shizuko",
    "matsumura.kou",
    "shimizu.kenji",
    "nishihara.kyou",
    "hirabayashi.atsushi",
    "toyama.takeshi",

    // generic german
    "lore.langer",
    "waldo.hall",
    "kirsa.stein",
    "amal.herrmann",
    "konstantin.kron",
    "grete.brauer",
    "apsel.arbeit",
    "maximilian.voigt",
    "werner.schmitz",
    "leon.herrmann",
    "elfriede.zimmermann",
    "august.peters",
    "niklaus.herrmann",
    "selma.tiedemann",
    "helene.schuster",
    "uschi.schumacher",
    "diederick.ziegler",
    "kilian.seidel",
    "ortrun.siegert",
    "annikin.sitz",

    // generic english
    "ged.hill",
    "arnold.peay",
    "samson.crawford",
    "goodwin.byrd",
    "tasha.guzman",
    "elaine.houle",
    "casey.clayton",
    "edgar.kim",
    "page.mills",
    "theo.gilbert",
    "tyler.boyd",
    "halbert.francis",
    "harley.patton",
    "georgette.hodgson",
    "jocelyn.males",
    "emily.woods",
    "timothy.watkins",
    "andrew.fraley",
    "elena.robertson",
    "larry.martin",
  ];

  let domains = [
    // CyberPunk 2077:
    "network-news-54.us",
    "nippon-network.jp",
    "dms.us",
    "worldwide-news.co.uk",
    "petrochem.us",
    "sovoil.ru",
    "arasaka.jp",
    "ebm.de",
    "iec.de",
    "kang-tao.cn",
    "segatari.jp",
    "microtech.us",
    "biotechnica.it",
    "rsvp.fr",

    // Shadowrun:
    "ares.us",
    "aztechnology.az",
    "evo.jp",
    "mitsuhama.jp",
    "renraku.jp",
    "saeder-Krupp.de",
    "wuxing.cn",

    // Bladerunner:
    "tyrell.us",
    "wallace.us",
    "shimago-dominguez.jp",

    // Westworld:
    "delos.us",
    "incite.us",
  ];

  let input_field = document.getElementById("username");

  input_field.value = usernames[user_selector % usernames.length] + "@" + domains[domain_selector % domains.length];
  input_field.setAttribute("disabled", "");

  document.addEventListener("DOMContentLoaded", () => document.getElementById("password").focus({ focusVisible: true }));


</script>

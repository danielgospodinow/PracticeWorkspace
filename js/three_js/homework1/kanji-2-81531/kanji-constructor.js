//Реших да си направя нов .js файл, за да работя върху
//задачата на по- чистичко. Дано не е проблем.
// : )

function makeRightSide(material, parentObj) 
{
    /* Common variables */
    var material = new THREE.MeshPhongMaterial({color:'gray',shininess:100});
    var extrudeSettings = { amount: 5, bevelEnabled: false};

    /* First part */
    var topLeft = new THREE.Shape();
    topLeft.moveTo(getMappedX(76), getMappedY(4));
    topLeft.lineTo(getMappedX(118), getMappedY(4));
    topLeft.lineTo(getMappedX(118), getMappedY(110));
    topLeft.lineTo(getMappedX(167), getMappedY(110));
    topLeft.lineTo(getMappedX(167), getMappedY(151));
    topLeft.lineTo(getMappedX(151), getMappedY(151));
    topLeft.lineTo(getMappedX(76), getMappedY(76));
    var topLeftGeometry = new THREE.ExtrudeGeometry(topLeft, extrudeSettings);
    var topLeftMesh = new THREE.Mesh(topLeftGeometry, material);

    /* Second part */
    var topLeft = new THREE.Shape();
    topLeft.moveTo(getMappedX(177), getMappedY(148));
    topLeft.lineTo(getMappedX(177), getMappedY(54));
    topLeft.lineTo(getMappedX(310), getMappedY(54));
    topLeft.lineTo(getMappedX(310), getMappedY(3));
    topLeft.lineTo(getMappedX(352), getMappedY(3));
    topLeft.lineTo(getMappedX(352), getMappedY(54));
    topLeft.lineTo(getMappedX(492), getMappedY(54));
    topLeft.lineTo(getMappedX(492), getMappedY(144));
    topLeft.lineTo(getMappedX(450), getMappedY(144));
    topLeft.lineTo(getMappedX(450), getMappedY(95));
    topLeft.lineTo(getMappedX(397), getMappedY(95));
    topLeft.lineTo(getMappedX(220), getMappedY(95));
    topLeft.lineTo(getMappedX(220), getMappedY(148));
    var topLeftGeometry = new THREE.ExtrudeGeometry(topLeft, extrudeSettings);
    var topLeftMesh2 = new THREE.Mesh(topLeftGeometry, material);

    /* Second part- kalashnikov part */
    var topLeft = new THREE.Shape();
    topLeft.moveTo(getMappedX(305), getMappedY(95));
    topLeft.quadraticCurveTo(getMappedX(294), getMappedY(178), getMappedX(212), getMappedY(212));
    topLeft.lineTo(getMappedX(180), getMappedY(180));
    topLeft.quadraticCurveTo(getMappedX(264), getMappedY(155), getMappedX(264), getMappedY(95));
    var topLeftGeometry = new THREE.ExtrudeGeometry(topLeft, extrudeSettings);
    var topLeftMesh3 = new THREE.Mesh(topLeftGeometry, material);

    /* Second part- second part */
    var topLeft = new THREE.Shape();
    topLeft.moveTo(getMappedX(397), getMappedY(95));
    topLeft.lineTo(getMappedX(397), getMappedY(151));
    topLeft.quadraticCurveTo(getMappedX(400), getMappedY(159), getMappedX(407), getMappedY(162));
    topLeft.lineTo(getMappedX(443), getMappedY(162));
    topLeft.quadraticCurveTo(getMappedX(459), getMappedY(154), getMappedX(456), getMappedY(144));
    topLeft.lineTo(getMappedX(472), getMappedY(144));
    topLeft.lineTo(getMappedX(498), getMappedY(159));
    topLeft.quadraticCurveTo(getMappedX(495), getMappedY(198), getMappedX(456), getMappedY(201));
    topLeft.lineTo(getMappedX(394), getMappedY(201));
    topLeft.quadraticCurveTo(getMappedX(357), getMappedY(201), getMappedX(357), getMappedY(165));
    topLeft.lineTo(getMappedX(357), getMappedY(95));
    var topLeftGeometry = new THREE.ExtrudeGeometry(topLeft, extrudeSettings);
    var topLeftMesh4 = new THREE.Mesh(topLeftGeometry, material);

    /* Big bottom part */
    var topLeft = new THREE.Shape();
    topLeft.moveTo(getMappedX(233), getMappedY(233));
    topLeft.quadraticCurveTo(getMappedX(251), getMappedY(208), getMappedX(263), getMappedY(178));
    topLeft.lineTo(getMappedX(275), getMappedY(166));
    topLeft.lineTo(getMappedX(304), getMappedY(183));
    topLeft.quadraticCurveTo(getMappedX(298), getMappedY(204), getMappedX(285), getMappedY(222));
    topLeft.lineTo(getMappedX(506), getMappedY(222));
    topLeft.lineTo(getMappedX(506), getMappedY(263));
    topLeft.lineTo(getMappedX(300), getMappedY(263));
    topLeft.lineTo(getMappedX(300), getMappedY(297));
    topLeft.lineTo(getMappedX(458), getMappedY(297));
    topLeft.lineTo(getMappedX(458), getMappedY(338));
    topLeft.lineTo(getMappedX(338), getMappedY(338));
    var topLeftGeometry = new THREE.ExtrudeGeometry(topLeft, extrudeSettings);
    var topLeftMesh5 = new THREE.Mesh(topLeftGeometry, material);

    /* Small bottom part */
    var topLeft = new THREE.Shape();
    topLeft.moveTo(getMappedX(376), getMappedY(376));
    topLeft.lineTo(getMappedX(479), getMappedY(376));
    topLeft.lineTo(getMappedX(479), getMappedY(416));
    topLeft.lineTo(getMappedX(416), getMappedY(416));
    var topLeftGeometry = new THREE.ExtrudeGeometry(topLeft, extrudeSettings);
    var topLeftMesh6 = new THREE.Mesh(topLeftGeometry, material);

    /* Adding to parent */
    addToParent(parentObj, topLeftMesh, topLeftMesh2, topLeftMesh3, topLeftMesh4, topLeftMesh5, topLeftMesh6);
}

function makeLeftSide(material, parentObj) 
{
    /* Common variables */
    var material = new THREE.MeshPhongMaterial({color:'gray',shininess:100});
    var extrudeSettings = { amount: 5, bevelEnabled: false};

    /* Basic rectangles */
    var bottomLeft = new THREE.Shape();
    bottomLeft.moveTo(getMappedX(76), getMappedY(76));
    bottomLeft.lineTo(getMappedX(76), getMappedY(110));
    bottomLeft.lineTo(getMappedX(5), getMappedY(110));
    bottomLeft.lineTo(getMappedX(5), getMappedY(151));
    bottomLeft.lineTo(getMappedX(76), getMappedY(151));
    bottomLeft.lineTo(getMappedX(76), getMappedY(452));
    bottomLeft.quadraticCurveTo(getMappedX(85), getMappedY(460), getMappedX(24), getMappedY(458));
    bottomLeft.lineTo(getMappedX(39), getMappedY(500));
    bottomLeft.quadraticCurveTo(getMappedX(120), getMappedY(490), getMappedX(118), getMappedY(454));
    bottomLeft.lineTo(getMappedX(118), getMappedY(151));
    bottomLeft.lineTo(getMappedX(151), getMappedY(151));
    bottomLeft.lineTo(getMappedX(76), getMappedY(76));
    var bottomLeftGeometry = new THREE.ExtrudeGeometry(bottomLeft, extrudeSettings);
    var bottomLeftMesh = new THREE.Mesh(bottomLeftGeometry, material);

    /* Add 01 */
    var bottomLeft = new THREE.Shape();
    bottomLeft.moveTo(getMappedX(76), getMappedY(275));
    bottomLeft.lineTo(getMappedX(0), getMappedY(305));
    bottomLeft.quadraticCurveTo(getMappedX(10), getMappedY(326), getMappedX(25), getMappedY(345));
    bottomLeft.lineTo(getMappedX(76), getMappedY(320));
    var bottomLeftGeometry = new THREE.ExtrudeGeometry(bottomLeft, extrudeSettings);
    var bottomLeftMesh1 = new THREE.Mesh(bottomLeftGeometry, material);

    /* Add 02 */
    var bottomLeft = new THREE.Shape();
    bottomLeft.moveTo(getMappedX(118), getMappedY(302));
    bottomLeft.lineTo(getMappedX(169), getMappedY(280));
    bottomLeft.lineTo(getMappedX(169), getMappedY(235));
    bottomLeft.lineTo(getMappedX(118), getMappedY(256));
    var bottomLeftGeometry = new THREE.ExtrudeGeometry(bottomLeft, extrudeSettings);
    var bottomLeftMesh2 = new THREE.Mesh(bottomLeftGeometry, material);

    /* Add 03 */
    var bottomLeft = new THREE.Shape();
    bottomLeft.moveTo(getMappedX(180), getMappedY(180));
    bottomLeft.quadraticCurveTo(getMappedX(178), getMappedY(181), getMappedX(162), getMappedY(187));
    bottomLeft.lineTo(getMappedX(191), getMappedY(221));
    bottomLeft.quadraticCurveTo(getMappedX(200), getMappedY(218), getMappedX(212), getMappedY(212));
    var bottomLeftGeometry = new THREE.ExtrudeGeometry(bottomLeft, extrudeSettings);
    var bottomLeftMesh3 = new THREE.Mesh(bottomLeftGeometry, material);

    /* Add 04 */
    var bottomLeft = new THREE.Shape();
    bottomLeft.moveTo(getMappedX(233), getMappedY(233));
    bottomLeft.quadraticCurveTo(getMappedX(204), getMappedY(275), getMappedX(149), getMappedY(313));
    bottomLeft.lineTo(getMappedX(182), getMappedY(345));
    bottomLeft.quadraticCurveTo(getMappedX(230), getMappedY(308), getMappedX(257), getMappedY(270));
    bottomLeft.lineTo(getMappedX(257), getMappedY(503));
    bottomLeft.lineTo(getMappedX(300), getMappedY(503));
    bottomLeft.lineTo(getMappedX(300), getMappedY(416));
    bottomLeft.lineTo(getMappedX(416), getMappedY(416));
    bottomLeft.lineTo(getMappedX(376), getMappedY(376));
    bottomLeft.lineTo(getMappedX(300), getMappedY(376));
    bottomLeft.lineTo(getMappedX(300), getMappedY(338));
    bottomLeft.lineTo(getMappedX(338), getMappedY(338));
    var bottomLeftGeometry = new THREE.ExtrudeGeometry(bottomLeft, extrudeSettings);
    var bottomLeftMesh4 = new THREE.Mesh(bottomLeftGeometry, material);

    addToParent(parentObj, bottomLeftMesh, bottomLeftMesh1, bottomLeftMesh2, bottomLeftMesh3, bottomLeftMesh4);
}

function addToParent(parentObj) 
{
    for(var i=0; i<arguments.length; i++) 
        parentObj.add(arguments[i]);
}

var xOffset = -10;
var yOffset = 10;

function getMappedX(imgX)
{
    return imgX * (20 / 507) + xOffset;
}

function getMappedY(imgY)
{
    return (-1 * imgY) * (20 / 507) + yOffset;
}
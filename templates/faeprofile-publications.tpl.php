<?php
/**
 * @file
 *
 * Available template variables are:
 *
 * $publications - An array of all publications.
 * $year         - An array of publication years, each of which contains an
 *                 array of publications.
 */
?>

<?php if ($year): ?>
  <h3>Selected publications</h3>
  <?php foreach ($year as $label => $publications): ?>
     <h4><?php print $label; ?></h4>
     <ul>
     <?php foreach ($publications as $publication): ?>
       <li><?php print $publication; ?></li>
    <?php endforeach; ?>
    </ul>
  <?php endforeach; ?>
<?php endif; ?>

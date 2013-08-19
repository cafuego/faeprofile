<?php
/**
 * @file
 */
?>

<?php if ($affiliations): ?>
  <h3>Member of</h3>
  <ul>
  <?php foreach ($affiliations as $affiliation): ?>
    <li><?php print $affiliation['organisation']; ?>. <?php print $affiliation['role']; ?>
  <?php endforeach; ?>
  </ul>
<?php endif; ?>


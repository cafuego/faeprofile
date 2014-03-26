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

<?php if($year): ?>
  <h3>Selected publications</h3>
	<?php foreach($year as $year_label => $pub_types): ?>  
		<h4><?php print $year_label; ?></h4>

		<?php
			uksort($pub_types, '_my_pub_type_compare');
		?>

		<?php foreach($pub_types as $pub_type_label => $pub_type): ?>	
			<h5><?php print $pub_type_label ?></h5>
			<ul>
			<?php foreach($pub_type as $single_pub): ?>
				<li><?php print $single_pub ?></li>
			<?php endforeach; ?>
			</ul>
		<?php endforeach; ?>
	<?php endforeach; ?>
<?php endif; ?>

